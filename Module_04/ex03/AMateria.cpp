#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria( void ) : _type( "null" ) {}

AMateria::AMateria( std::string const & type ) : _type( type ) {}

AMateria::~AMateria( void ) {}

AMateria::AMateria( const AMateria & copy ) {
    *this = copy;
}

AMateria & AMateria::operator=( const AMateria & copy ) {
    this->_type = copy.getType();
    return ( *this );
}

std::string const &    AMateria::getType(  void  ) const {
    return ( this->_type );
}

void AMateria::use( ICharacter & target  ) {
    std::cout << "Character " << target.getName()
        << "used an item" << std::endl;
}
