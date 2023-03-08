#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
    std::cout << "Dog constructor is called" << std::endl;
}

Dog::Dog( std::string type ) : Animal(type) {
    std::cout << "Dog constructor is called" << std::endl;
}

Dog::~Dog( void ) {
    std::cout << "Dog destructor is called" << std::endl;
}

Dog::Dog( Dog & copy ) : Animal(copy) {
    std::cout << "Cat copy constructor is called" << std::endl;
    *this = copy;
}

Dog & Dog::operator=( Dog const & copy ) {
    std::cout << "Dog copy assignment operator is called" << std::endl;
    Animal::operator=(copy);
    return ( *this );
}

std::string Dog::_getSound( void ) const {
    return ("WOAFF WOAFF!!");
}
