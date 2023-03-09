#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal {
    private:
        std::string _getSound( void ) const;

    public:
        Dog( void );
        Dog( std::string const & Animal );
        ~Dog( void );
        Dog( Dog const & copy );
        Dog & operator=( Dog const & copy );

        void makeSound( void ) const;
};

#endif

