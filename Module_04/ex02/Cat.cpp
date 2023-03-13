#include "Cat.hpp"

Cat::Cat( void ) : AAnimal("Cat") {
    this->_brain = new Brain();
    std::cout << "Cat constructor is called" << std::endl;
}

Cat::Cat( std::string const & type ) : AAnimal(type) {
    this->_brain = new Brain();
    std::cout << "Cat constructor is called" << std::endl;
}

Cat::~Cat( void ) {
    delete this->_brain;
    std::cout << "Cat destructor is called" << std::endl;
}

Cat::Cat( Cat const & copy ) : AAnimal(copy) {
    std::cout << "Cat copy constructor is called" << std::endl;
    this->_brain = NULL;
    *this = copy;
}

Cat & Cat::operator=( Cat const & copy ) {
    std::cout << "Cat copy assignment operator is called" << std::endl;
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain(*copy._brain);
    AAnimal::operator=(copy);
    return ( *this );
}

void Cat::makeSound( void ) const {
    std::cout << "Meoww!?" << std::endl;
}
