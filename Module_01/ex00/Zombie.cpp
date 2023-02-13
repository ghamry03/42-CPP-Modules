#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
	this->_name = name;
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << "Zombie " << this->_name << " has been destroyed" << std::endl;
	return ;
}

void	Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
