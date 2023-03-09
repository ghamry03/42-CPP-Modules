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
        FragTrap( std::string const & name );
        virtual ~FragTrap( void );
        FragTrap( FragTrap const & copy );

        /**** public operators overload  ****/
        FragTrap & operator=( FragTrap const & copy );

        /**** public member functions ****/
        void    highFivesGuys( void ) const;
};

#endif

