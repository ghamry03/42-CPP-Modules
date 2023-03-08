#include "FragTrap.hpp"

std::string FragTrap::getType( void ) const {
    return ("FragTrap");
}

FragTrap::FragTrap( void ) : ClapTrap() {
    std::cout << getType().append(" ") << this->_name
        << " joined the party using default constructor" << std::endl;
    this->_health = 100;
    this->_energy = 50;
    this->_attackDmg = 20;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {
    std::cout << getType().append(" ") << this->_name
        << " joined the party" << std::endl;
    this->_health = 100;
    this->_energy = 50;
    this->_attackDmg = 20;
}

FragTrap::~FragTrap( void ) {
    std::cout << getType().append(" ") << this->_name
        << " left the party" << std::endl;
}

FragTrap::FragTrap( FragTrap const & copy ) : ClapTrap(copy) {
    *this = copy;
}

FragTrap & FragTrap::operator=( FragTrap const & copy ) {
    this->_name = copy._name;
    this->_health = copy._health;
    this->_energy = copy._energy;
    this->_attackDmg = copy._attackDmg;
    return ( *this );
}

void    FragTrap::highFivesGuys( void ) const {
    std::cout << getType().append(" ") << _name
        << " requested high five" << std::endl;
}
