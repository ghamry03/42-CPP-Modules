#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
    private:
        std::string         _name;
        unsigned int        _health;
        unsigned int        _energy;
        unsigned int        _attackDmg;
        virtual std::string getType( void ) const;

    public:
        ClapTrap( void );
        ClapTrap( const std::string & name );
        ~ClapTrap( void );
        ClapTrap( const ClapTrap & copy );
        ClapTrap & operator=( const ClapTrap & copy );

        void attack( const std::string & target );
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif

