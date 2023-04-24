#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain * _brain;
        Dog( std::string const & type );

    public:
        Dog( void );
        ~Dog( void );
        Dog( Dog const & copy );
        Dog & operator=( Dog const & copy );

        void makeSound( void ) const;
};

#endif

