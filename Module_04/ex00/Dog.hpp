#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal {
    private:
        std::string _getSound( void ) const;

    public:
        Dog( void );
        Dog( std::string Animal );
        ~Dog( void );
        Dog( Dog & copy );
        Dog & operator=( Dog const & copy );

};

#endif

