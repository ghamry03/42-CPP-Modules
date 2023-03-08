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

    private:
        /**** private member functions ****/
        virtual std::string getType( void ) const;

    public:
        /**** public constructors && destructors ****/
        ClapTrap( void );
        ClapTrap( const std::string & name );
        ~ClapTrap( void );
        ClapTrap( const ClapTrap & copy );

        /**** public operators overload  ****/
        ClapTrap & operator=( const ClapTrap & copy );

        /**** public member functions ****/
        void attack( const std::string & target );
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif

