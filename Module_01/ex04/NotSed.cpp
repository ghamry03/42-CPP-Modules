#include "NotSed.hpp"

NotSed::NotSed( void ) {
	this->_isError = 0;
	return ;
}

NotSed::~NotSed( void ) {
	this->_inFile.close();
	this->_outFile.close();
	return ;
}

void	NotSed::setInFilePath ( std::string filePath ) {
	this->_inFilePath = filePath;
}

void	NotSed::setOutFilePath ( std::string filePath ) {
	this->_outFilePath = filePath;
}

int		NotSed::openInFile( void ) {
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

void	NotSed::readInFile( void ) {
	char		c;

	if ( _isError )
		return ;
	while (_inFile.get(c))
		_inFileText += c;
}

int		NotSed::openOutFile( void ) {
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

void	NotSed::replaceText( std::string findWord, std::string replaceWord ) {
	ssize_t		found;

	if ( _isError )
			return ;
	for ( size_t i = 0; i < _inFileText.size(); i++ ) {
		found = _inFileText.find( findWord, i );
		if ( found != -1 && (size_t)found == i ) {
			_replacedText += replaceWord;
			i += findWord.size() - 1;
		} else
			_replacedText += _inFileText[i];
	}
}

void	NotSed::writeToOutFile( void ) {
	if ( _isError )
		return ;
	_outFile << _replacedText;
}
