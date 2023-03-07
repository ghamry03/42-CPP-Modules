#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    private:
        /**** private member functions ****/
        std::string getType( void );

    public:
        /**** private constructors && destructors ****/
        ScavTrap( void );
        ScavTrap( std::string name );
        ~ScavTrap( void );
        ScavTrap( ScavTrap & copy );

        /**** public operators overload  ****/
        ScavTrap & operator=( ScavTrap const & copy );

        /**** public member functions ****/
        void    guardGate( void );
};

#endif

