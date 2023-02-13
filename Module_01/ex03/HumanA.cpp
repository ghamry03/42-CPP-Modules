#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _weapon(weapon) {
	this->_name = name;
	return ;
}

HumanA::~HumanA( void ) {
	return ;
}

void	HumanA::attack( void ) {
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << std::endl;
}
