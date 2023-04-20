#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice( void ) : AMateria( "ice" ) {
    this->_type = "ice";
}

Ice::~Ice( void ) {}

Ice::Ice( const Ice & copy ) : AMateria( copy  ) {
    *this = copy;
}

Ice & Ice::operator=( const Ice & copy ) {
    this->_type = copy.getType();
    return ( *this );
}

AMateria * Ice::clone( void ) const {
    Ice * ret = new Ice( *this );
    return ( ret );
}

void Ice::use( ICharacter & target ) {
    std::cout << "* shoots an ice bolt at "
        << target.getName() << " *" << std::endl;
}
