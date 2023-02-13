#include "HumanB.hpp"

HumanB::HumanB( std::string name ) {
	this->_name = name;
	this->_weapon = NULL;
	return ;
}

// HumanB::HumanB( std::string name, const std::string& weapon ) {
// 	this->_name = name;
// 	this->_weapon = &weapon;
// 	return ;
// }

HumanB::~HumanB( void ) {
	return ;
}

void	HumanB::setWeapon( Weapon& weapon ) {
	this->_weapon = &weapon;
}

void	HumanB::attack( void ) {
	std::string		weaponType;

	this->_weapon ? weaponType = _weapon->getType() : weaponType = "hands";
	std::cout << this->_name << " attacks with their "
		<< weaponType << std::endl;
}
