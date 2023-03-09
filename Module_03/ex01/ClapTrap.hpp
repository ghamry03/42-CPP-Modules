#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
    protected:
        /**** protected member variables ****/
        std::string         _name;
        unsigned int        _health;
        unsigned int        _energy;
        unsigned int        _attackDmg;

        /**** private member functions ****/
        virtual std::string getType( void ) const;

    public:
        /**** public constructors && destructors ****/
        ClapTrap( void );
        ClapTrap( std::string const & name );
        ~ClapTrap( void );
        ClapTrap( ClapTrap const & copy );

        /**** public operators overload  ****/
        ClapTrap & operator=( ClapTrap const & copy );

        /**** public member functions ****/
        void attack( std::string const & target );
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif

