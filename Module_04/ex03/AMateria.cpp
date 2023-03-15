#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria( void ) : _type("null") {
    std::cout << "AMateria default contructor is called" << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type) {
    std::cout << "AMateria contructor is called" << std::endl;
}

AMateria::~AMateria( void ) {
    std::cout << "AMateria destructor is called" << std::endl;
}

AMateria::AMateria( AMateria const & copy ) {
    std::cout << "AMateria copy constructor is called" << std::endl;
    *this = copy;
}

AMateria & AMateria::operator=( AMateria const & copy ) {
    std::cout << "AMateria copy assignment operator is called" << std::endl;
    this->_type = copy._type;
    return ( *this );
}

std::string const &    AMateria::getType( void ) const {
    return (this->_type);
}

void AMateria::use( ICharacter & target ) {
    std::cout << "Character " << target.getName()
        << "used an item" << std::endl;
}
