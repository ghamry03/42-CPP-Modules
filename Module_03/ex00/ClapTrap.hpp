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
        ClapTrap( std::string const & name );
        ~ClapTrap( void );
        ClapTrap( ClapTrap const & copy );
        ClapTrap & operator=( ClapTrap const & copy );

        void attack( std::string const & target );
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif

