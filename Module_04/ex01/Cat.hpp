#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain * _brain;
        Cat( std::string const & type );

    public:
        Cat( void );
        ~Cat( void );
        Cat( Cat const & copy );
        Cat & operator=( Cat const & copy );

        void makeSound( void ) const;
};

#endif

