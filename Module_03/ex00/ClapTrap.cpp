#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _health(10), _energy(10), _attackDmg(10) {
    std::cout << "ClapTrap " << _name << " joined the party" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "ClapTrap " << _name << " left the party" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap & copy ) {
    *this = copy;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & copy ) {
    this->_name = copy._name;
    this->_health = copy._health;
    this->_energy = copy._energy;
    this->_attackDmg = copy._attackDmg;
    return ( *this );
}

void    ClapTrap::attack( const std::string & target ) {
    if (!this->_energy || !this->_health)
        return ;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
        << _attackDmg << " points of damage!" << std::endl;
    this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_health)
        return ;
    std::cout << "ClapTrap " << this->_name << " lost "
        << amount << " hit points" << std::endl;
    this->_health -= amount;
    std::cout << "bruh: " << this->_health << std::endl;
    if (this->_health <= 0)
        std::cout << "ClapTrap " << this->_name
            << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!this->_energy || !this->_health)
        return ;
    std::cout << "ClapTrap " << this->_name << " gained "
        << amount << " hit points back" << std::endl;
    this->_health += amount;
    this->_energy--;
}
