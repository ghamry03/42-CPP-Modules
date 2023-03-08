#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    private:
        /**** private member functions ****/
        std::string getType( void ) const;

    public:
        /**** private constructors && destructors ****/
        ScavTrap( void );
        ScavTrap( const std::string & name );
        ~ScavTrap( void );
        ScavTrap( const ScavTrap & copy );

        /**** public operators overload  ****/
        ScavTrap & operator=( const ScavTrap & copy );

        /**** public member functions ****/
        void    guardGate( void );
};

#endif

