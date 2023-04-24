#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
    std::cout << "Dog constructor is called" << std::endl;
}

Dog::Dog( std::string const & type ) : Animal(type) {
    std::cout << "Dog constructor is called" << std::endl;
}

Dog::~Dog( void ) {
    std::cout << "Dog destructor is called" << std::endl;
}

Dog::Dog( Dog const & copy ) : Animal(copy) {
    std::cout << "Dog copy constructor is called" << std::endl;
    *this = copy;
}

Dog & Dog::operator=( Dog const & copy ) {
    std::cout << "Dog copy assignment operator is called" << std::endl;
    Animal::operator=(copy);
    return ( *this );
}

void Dog::makeSound( void ) const {
    std::cout << "Woaff!?" << std::endl;
}
