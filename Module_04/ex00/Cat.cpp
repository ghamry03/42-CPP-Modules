#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
    std::cout << "Cat constructor is called" << std::endl;
}

Cat::Cat( std::string type ) : Animal(type) {
    std::cout << "Cat constructor is called" << std::endl;
}

Cat::~Cat( void ) {
    std::cout << "Cat destructor is called" << std::endl;
}

Cat::Cat( Cat & copy ) : Animal(copy) {
    std::cout << "Cat copy constructor is called" << std::endl;
    *this = copy;
}

Cat & Cat::operator=( Cat const & copy ) {
    std::cout << "Cat copy assignment operator is called" << std::endl;
    Animal::operator=(copy);
    return ( *this );
}

std::string Cat::_getSound( void ) const {
    return ("MEOWW!!");
}
