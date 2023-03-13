#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
    private:
        Brain * _brain;

    public:
        Dog( void );
        Dog( std::string const & AAnimal );
        ~Dog( void );
        Dog( Dog const & copy );
        Dog & operator=( Dog const & copy );

        void makeSound( void ) const;
};

#endif

