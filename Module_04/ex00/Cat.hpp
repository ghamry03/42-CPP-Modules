#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {
    private:
        std::string _getSound( void ) const;

    public:
        Cat( void );
        Cat( std::string type );
        ~Cat( void );
        Cat( Cat & copy );
        Cat & operator=( Cat const & copy );

};

#endif

