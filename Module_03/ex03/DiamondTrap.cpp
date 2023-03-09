#include "DiamondTrap.hpp"

std::string DiamondTrap::getType( void ) const {
    return ("DiamondTrap");
}

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << getType().append(" ") << this->_name
        << " joined the party" << std::endl;
    ClapTrap::_name = "default_clap_name";
    this->_health = FragTrap::_health;
    this->_energy = ScavTrap::_energy;
    this->_attackDmg = FragTrap::_attackDmg;
}

DiamondTrap::DiamondTrap( std::string const & name )
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
        this->_name = name;
        this->_health = FragTrap::_health;
        this->_energy = ScavTrap::_energy;
        this->_attackDmg = FragTrap::_attackDmg;
        std::cout << getType().append(" ") << this->_name
            << " joined the party" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << getType().append(" ") << this->_name
        << " left the party" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & copy ) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
    *this = copy;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & copy ) {
    this->_name = copy._name;
    this->_health = copy._health;
    this->_energy = copy._energy;
    this->_attackDmg = copy._attackDmg;
    return ( *this );
}

void    DiamondTrap::wohAmI( void ) const {
    std::cout << "DiamondTrap name " << this->_name
        << " - ClapTrap name " << ClapTrap::_name << std::endl;
}

void    DiamondTrap::attack( const std::string & target ) {
    ScavTrap::attack(target);
}
