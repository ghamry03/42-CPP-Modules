#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria {
    private:

    public:
        Cure( void );
        ~Cure( void );
        Cure( const Cure & copy );
        Cure & operator=( const Cure & copy );

        AMateria * clone( void ) const;
        void use( ICharacter& target );
};

#endif
