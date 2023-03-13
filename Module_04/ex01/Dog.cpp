#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
    this->_brain = new Brain();
    std::cout << "Dog constructor is called" << std::endl;
}

Dog::Dog( std::string const & type ) : Animal(type) {
    this->_brain = new Brain();
    std::cout << "Dog constructor is called" << std::endl;
}

Dog::~Dog( void ) {
    delete this->_brain;
    std::cout << "Dog destructor is called" << std::endl;
}

Dog::Dog( Dog const & copy ) : Animal(copy) {
    std::cout << "Dog copy constructor is called" << std::endl;
    this->_brain = NULL;
    *this = copy;
}

Dog & Dog::operator=( Dog const & copy ) {
    std::cout << "Dog copy assignment operator is called" << std::endl;
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain(*copy._brain);
    Animal::operator=(copy);
    return ( *this );
}

void Dog::makeSound( void ) const {
    std::cout << "Woaff!?" << std::endl;
}
