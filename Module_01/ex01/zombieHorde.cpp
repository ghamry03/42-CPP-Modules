#include "Zombie.hpp"
#include <iostream>

Zombie	*zombieHorde( int N, std::string name ) {
	if ( N < 0 ) {
		std::cout << "Invalid number" << std::endl;
		return ( NULL );
	}
	Zombie	*zombs = new Zombie[N];
	for ( int i = 0; i < N; i++ ) {
		zombs[i].setName(name);
	}
	return (zombs);
}
