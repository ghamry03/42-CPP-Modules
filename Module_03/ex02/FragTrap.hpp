#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    private:
        /**** private member functions ****/
        std::string getType( void );

    public:
        /**** private constructors && destructors ****/
        FragTrap( void );
        FragTrap( std::string name );
        ~FragTrap( void );
        FragTrap( FragTrap & copy );

        /**** public operators overload  ****/
        FragTrap & operator=( FragTrap const & copy );

        /**** public member functions ****/
        void    highFivesGuys( void );
};

#endif

