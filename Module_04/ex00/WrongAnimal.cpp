#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal") {
    std::cout << "WrongAnimal constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string const & type ) : _type(type) {
    std::cout << "WrongAnimal constructor is called" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
    std::cout << "WrongAnimal destructor is called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & copy ) {
    std::cout << "WrongAnimal copy constructor is called" << std::endl;
    *this = copy;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & copy ) {
    std::cout << "WrongAnimal copy assignment operator is called" << std::endl;
    this->_type = copy._type;
    return ( *this );
}

std::string WrongAnimal::getType( void ) const {
    return ( this->_type );
}

void WrongAnimal::makeSound( void ) const {
    std::cout << "WrongAnimals don't make sound .." << std::endl;
}
