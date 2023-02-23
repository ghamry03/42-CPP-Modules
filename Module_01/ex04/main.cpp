# include "File.hpp"

int main ( int ac, char **av ) {
	File	file;

	if ( ac != 4 ) {
		std::cerr << "Invalid number of arguments" << std::endl;
		return ( 0 );
	}
	return ( file.sed( av[1], av[2], av[3] ) );
}
