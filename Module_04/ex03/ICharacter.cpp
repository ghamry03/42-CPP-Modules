#include "ICharacter.hpp"

ICharacter::ICharacter( void ) {
}

ICharacter::~ICharacter( void ) {
}

ICharacter::ICharacter( ICharacter const & copy ) {
    *this = copy;
}

ICharacter & ICharacter::operator=( ICharacter const & copy ) {
    (void)copy;
    return ( *this );
}

