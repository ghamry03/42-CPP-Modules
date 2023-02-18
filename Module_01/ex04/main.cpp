# include "NotSed.hpp"

int		notSed( char** av ) {
	NotSed		file;

	file.setInFilePath( av[1] );
	if ( !file.openInFile() )
		return ( 0 );
	file.readInFile();
	file.replaceText( av[2], av[3] );
	file.setOutFilePath( std::string( av[1] ).append( ".replace" ) );
	if ( !file.openOutFile() )
		return ( 0 );
	file.writeToOutFile();
	return ( 1 );
}

int main ( int ac, char **av ) {
	if ( ac != 4 ) {
		std::cerr << "Invalid number of arguments" << std::endl;
		return ( 0 );
	}
		
	return ( notSed( av ) );
}
