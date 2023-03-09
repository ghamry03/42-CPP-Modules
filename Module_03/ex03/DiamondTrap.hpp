#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;
        std::string getType( void ) const;

    public:
        DiamondTrap( void );
        DiamondTrap( std::string const & name );
        ~DiamondTrap( void );
        DiamondTrap( DiamondTrap const & copy );
        DiamondTrap & operator=( DiamondTrap const & copy );

        void    wohAmI( void ) const;
        void    attack( std::string const & target );
};

#endif

