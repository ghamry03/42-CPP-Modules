#include "HumanB.hpp"

HumanB::HumanB( std::string name ) {
	this->_name = name;
	this->_weapon = NULL;
	return ;
}

HumanB::HumanB( std::string name, const std::string& weapon ) {
	this->_name = name;
	this->_weapon = &weapon;
	return ;
}

HumanB::~HumanB( void ) {
	return ;
}

void	HumanB::attack( void ) {
	std::string		weapon;

	this->_weapon ? weapon = *_weapon : weapon = "null";
	std::cout << this->_name << " attacks with their "
		<< weapon << std::endl;
}
