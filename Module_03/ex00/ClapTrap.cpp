#include "ClapTrap.hpp"

std::string ClapTrap::getType( void ) const {
    return ( "ClapTrap" );
}

ClapTrap::ClapTrap( void ) : _name("default"), _health(10), _energy(10), _attackDmg(10) {
    std::cout << getType().append(" ") << " joined the party using default constructor" << std::endl;
}

ClapTrap::ClapTrap( const std::string & name ) : _name(name), _health(10), _energy(10), _attackDmg(10) {
    std::cout << getType().append(" ") << _name << " joined the party" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
    std::cout << getType().append(" ") << _name << " left the party" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & copy ) {
    *this = copy;
}

ClapTrap & ClapTrap::operator=( const ClapTrap & copy ) {
    this->_name = copy._name;
    this->_health = copy._health;
    this->_energy = copy._energy;
    this->_attackDmg = copy._attackDmg;
    return ( *this );
}

void    ClapTrap::attack( const std::string & target ) {
    if (!this->_energy || !this->_health) {
        std::cout << getType().append(" ") << this->_name
            << " is out of energy" << std::endl;
        return ;
    }
    std::cout << getType().append(" ") << this->_name << " attacks " << target << ", causing "
        << _attackDmg << " points of damage!" << std::endl;
    this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_health <= amount) {
        std::cout << getType().append(" ") << this->_name
            << " is dead" << std::endl;
        return ;
    }
    std::cout << getType().append(" ") << this->_name << " lost "
        << amount << " hit points" << std::endl;
    this->_health -= amount;
    std::cout << "bruh: " << this->_health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!this->_energy || !this->_health) {
        std::cout << getType().append(" ") << this->_name
            << " is out of energy" << std::endl;
        return ;
    }
    std::cout << getType().append(" ") << this->_name << " gained "
        << amount << " hit points back" << std::endl;
    this->_health += amount;
    this->_energy--;
}
