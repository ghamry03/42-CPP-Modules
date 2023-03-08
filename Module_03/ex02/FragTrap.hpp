#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    private:
        /**** private member functions ****/
        std::string getType( void ) const;

    public:
        /**** private constructors && destructors ****/
        FragTrap( void );
        FragTrap( const std::string name );
        virtual ~FragTrap( void );
        FragTrap( const FragTrap & copy );

        /**** public operators overload  ****/
        FragTrap & operator=( const FragTrap & copy );

        /**** public member functions ****/
        void    highFivesGuys( void ) const;
};

#endif

