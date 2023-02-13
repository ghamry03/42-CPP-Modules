#include "Weapon.hpp"

Weapon::Weapon( void ) {
	return ;
}

Weapon::~Weapon( void ) {
	return ;
}

void	Weapon::setType( std::string type ) {
	this->_type = type;
}

const std::string&	Weapon::getType ( void ) {
	return (this->_type);
}
