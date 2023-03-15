#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
    public:
        Ice( void );
        ~Ice( void );
        Ice( Ice const & copy );
        Ice & operator=( Ice const & copy );

        Ice * clone( void ) const;
        void  use( ICharacter & target );

};

#endif
