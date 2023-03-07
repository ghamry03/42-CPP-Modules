#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
    private:
        std::string     _name;
        unsigned int    _health;
        unsigned int    _energy;
        unsigned int    _attackDmg;

    public:
        ClapTrap( void );
        ClapTrap( std::string name );
        ~ClapTrap( void );
        ClapTrap( ClapTrap & copy );
        ClapTrap & operator=( ClapTrap const & copy );

        void attack( const std::string & target );
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif

