#include "HumanA.hpp"
#include "HumanB.hpp"

int main( void ) {
	// Weapon for Human A and Human B
	Weapon weapon;
	weapon.setType("Bate5aa");

	// Humana A
	HumanA humanA = HumanA( "HumanA", weapon.getType() );
	humanA.attack();

	// Human B with a weapon
	HumanB humanB2 = HumanB( "HumanB2", weapon.getType() );
	humanB2.attack();

	// Human B without a weapon
	HumanB humanB1 = HumanB( "HumanB1" );
	humanB1.attack();
}
