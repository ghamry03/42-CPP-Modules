#include "Zombie.hpp"

int main( void ) {
	Zombie *zomb = newZombie( "newZombie" );
	zomb->announce();
	randomChump( "randomChump" );
	delete zomb;
}
