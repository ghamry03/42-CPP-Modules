#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
    public:
        Cure( void );
        ~Cure( void );
        Cure( Cure const & copy );
        Cure & operator=( Cure const & copy );

        Cure * clone( void ) const;
        void   use( ICharacter & target );
};

#endif
