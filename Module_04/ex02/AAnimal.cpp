#include "AAnimal.hpp"

AAnimal::AAnimal( std::string const & type ) : _type(type) {
    std::cout << "AAnimal constructor is called" << std::endl;
}

AAnimal::~AAnimal( void ) {
    std::cout << "AAnimal destructor is called" << std::endl;
}

AAnimal::AAnimal( AAnimal const & copy ) {
    std::cout << "AAnimal copy constructor is called" << std::endl;
    *this = copy;
}

AAnimal & AAnimal::operator=( AAnimal const & copy ) {
    std::cout << "AAnimal copy assignment operator is called" << std::endl;
    this->_type = copy._type;
    return ( *this );
}

std::string AAnimal::getType( void ) const {
    return ( this->_type );
}

void AAnimal::makeSound( void ) const {
    std::cout << "AAnimals don't make sound .." << std::endl;
}
