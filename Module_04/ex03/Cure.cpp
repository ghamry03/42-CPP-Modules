#include "Cure.hpp"

Cure::Cure( void ) : AMateria("ice") {
}

Cure::~Cure( void ) {
}

Cure::Cure( Cure const & copy ) : AMateria(copy) {
    *this = copy;
}

Cure & Cure::operator=( Cure const & copy ) {
    this->AMateria::operator=(copy);
    return (*this);
}

Cure * Cure::clone( void ) const {
    Cure * ret = new Cure( *this);
    return(ret);
}

void    Cure::use( ICharacter & target ) {
    std::cout << "Heals " << target.getName() << "’s wound" << std::endl;
}
