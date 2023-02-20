#include "Harl.hpp"

int	harlFilter( std::string input ) {
	Harl	harl;

	switch ( harl.startingLevel( input ) ) {
		case 0:
			harl.complain( "DEBUG" );
		case 1:
			harl.complain( "INFO" );
		case 2:
			harl.complain( "WARNING" );
		case 3:
			harl.complain( "ERROR" );
			break ;
		default:
			std::cout << "Invalid argument" << std::endl;
	}
	return ( true ); }

int	main( int ac, char **av ) {
	if ( ac != 2 ) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return ( 0 );
	}
	return ( harlFilter( av[1] ) );
}
