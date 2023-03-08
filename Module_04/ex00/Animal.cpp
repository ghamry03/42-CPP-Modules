#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal") {
    std::cout << "Animal constructor is called" << std::endl;
}

Animal::Animal( std::string type ) : _type(type) {
    std::cout << "Animal constructor is called" << std::endl;
}

Animal::~Animal( void ) {
    std::cout << "Animal destructor is called" << std::endl;
}

Animal::Animal( Animal & copy ) {
    std::cout << "Animal copy constructor is called" << std::endl;
    *this = copy;
}

Animal & Animal::operator=( Animal const & copy ) {
    std::cout << "Animal copy assignment operator is called" << std::endl;
    this->_type = copy._type;
    return ( *this );
}

std::string Animal::getType( void ) const {
    return ( this->_type );
}

void Animal::makeSound( void ) const {
    std::cout << this->_getSound() << std::endl;
}

std::string Animal::_getSound( void ) const {
    return ("Animals don't make sound ..");
}
