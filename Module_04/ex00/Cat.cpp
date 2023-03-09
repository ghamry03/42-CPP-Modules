#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
    std::cout << "Cat constructor is called" << std::endl;
}

Cat::Cat( std::string const & type ) : Animal(type) {
    std::cout << "Cat constructor is called" << std::endl;
}

Cat::~Cat( void ) {
    std::cout << "Cat destructor is called" << std::endl;
}

Cat::Cat( Cat const & copy ) : Animal(copy) {
    std::cout << "Cat copy constructor is called" << std::endl;
    *this = copy;
}

Cat & Cat::operator=( Cat const & copy ) {
    std::cout << "Cat copy assignment operator is called" << std::endl;
    Animal::operator=(copy);
    return ( *this );
}

void Cat::makeSound( void ) const {
    std::cout << "Meoww!?" << std::endl;
}
