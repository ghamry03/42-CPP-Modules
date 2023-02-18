#include "Zombie.hpp"

int	main( void ) {
	int		num = -69;
	Zombie	*zombs = zombieHorde( num, "bruh" );

	for ( int i = 0; i < num; i++ ) {
		zombs[i].announce();
	}
	delete [] (zombs);
}
