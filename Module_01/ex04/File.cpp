#include "File.hpp"

File::File( void ) {
	this->_isError = 0;
	return ;
}

File::~File( void ) {
	this->_inFile.close();
	this->_outFile.close();
	return ;
}

void	File::setInFilePath ( std::string filePath ) {
	this->_inFilePath = filePath;
}

void	File::setOutFilePath ( std::string filePath ) {
	this->_outFilePath = filePath;
}

int		File::openInFile( void ) {
	if ( _isError )
		return ( 1 );
	this->_inFile.open( _inFilePath.c_str() );
	if ( !_inFile.is_open() ) {
		this->_isError = 1;
		std::cerr << "Invalid infile path" << std::endl;
		return ( 0 );
	}
	return ( 1 );
}

void	File::readInFile( void ) {
	std::string		line;

	if ( _isError )
		return ;
	while ( std::getline( _inFile, line ) ) {
		_inFileText.append(line);
		if ( !_inFile.eof() )
			_inFileText.append( "\n" );
	}
}

int		File::openOutFile( void ) {
	if ( _isError )
		return ( 0 );
	this->_outFile.open( _outFilePath.c_str() );
	if ( !_outFile.is_open() ) {
		this->_isError = 1;
		std::cerr << "Invalid outfile path" << std::endl;
		return ( 0 );
	}
	return ( 1 );
}

void	File::replaceText( std::string findWord, std::string replaceWord ) {
	size_t	found;

	if ( _isError )
			return ;
	for ( size_t i = 0; i < _inFileText.size(); i++ ) {
		found = _inFileText.find( findWord, i );
		if ( found != std::string::npos && (size_t)found == i ) {
			_replacedText += replaceWord;
			i += findWord.size() - 1;
		} else
			_replacedText += _inFileText[i];
	}
}

void	File::writeToOutFile( void ) {
	if ( _isError )
		return ;
	_outFile << _replacedText;
}

int	File::sed( std::string fileName, std::string findWord, std::string replaceWord ) {
	this->setInFilePath( fileName );
	if ( !this->openInFile() )
		return ( 0 );
	this->readInFile();
	this->replaceText( findWord, replaceWord );
	this->setOutFilePath( std::string( fileName ).append( ".replace" ) );
	if ( !this->openOutFile() )
		return ( 0 );
	this->writeToOutFile();
	return ( 1 );
}
