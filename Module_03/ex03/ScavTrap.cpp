#include "ScavTrap.hpp"

std::string ScavTrap::getType( void ) {
    return ("ScavTrap");
}

ScavTrap::ScavTrap( void ) : ClapTrap() {
    std::cout << getType().append(" ") << this->_name
        << " joined the party using default constructor" << std::endl;
    this->_health = 100;
    this->_energy = 50;
    this->_attackDmg = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
    std::cout << getType().append(" ") << this->_name
        << " joined the party" << std::endl;
    this->_health = 100;
    this->_energy = 50;
    this->_attackDmg = 20;
}

ScavTrap::~ScavTrap( void ) {
    std::cout << getType().append(" ") << this->_name
        << " left the party" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap & copy ) : ClapTrap(copy) {
    *this = copy;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & copy ) {
    this->_name = copy._name;
    this->_health = copy._health;
    this->_energy = copy._energy;
    this->_attackDmg = copy._attackDmg;
    return ( *this );
}

void    ScavTrap::attack( const std:: string & target ) {
    if (!this->_energy || !this->_health) {
        std::cout << "ScavTrap " << this->_name
            << " is out of energy" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
        << _attackDmg << " points of damage!" << std::endl;
    this->_energy--;
}

void    ScavTrap::guardGate( void ) {
    std::cout << getType().append(" ") << this->_name
        << " is guarding the gate" << std::endl;
}
