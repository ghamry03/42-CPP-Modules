#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    private:
        /**** private member functions ****/
        std::string getType( void ) const;

    public:
        /**** private constructors && destructors ****/
        ScavTrap( void );
        ScavTrap( std::string const & name );
        ~ScavTrap( void );
        ScavTrap( ScavTrap const & copy );

        /**** public operators overload  ****/
        ScavTrap & operator=( ScavTrap const & copy );

        /**** public member functions ****/
        void    attack( std::string const & target );
        void    guardGate( void ) const;
};

#endif

