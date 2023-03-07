#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;
        std::string getType( void );

    public:
        DiamondTrap( void );
        DiamondTrap( std::string name );
        ~DiamondTrap( void );
        DiamondTrap( DiamondTrap & copy );
        DiamondTrap & operator=( DiamondTrap const & copy );

        void    wohAmI( void );
};

#endif

