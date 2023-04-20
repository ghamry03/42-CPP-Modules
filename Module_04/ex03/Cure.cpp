#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure( void ) : AMateria( "cure" ) {
}

Cure::~Cure( void ) {}

Cure::Cure( const Cure & copy ) : AMateria( copy ) {
    *this = copy;
}

Cure & Cure::operator=( const Cure & copy ) {
    this->_type = copy.getType();
    return ( *this );
}

AMateria * Cure::clone( void ) const {
    Cure * ret = new Cure(  *this  );
    return ( ret );
}

void Cure::use( ICharacter & target ) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
