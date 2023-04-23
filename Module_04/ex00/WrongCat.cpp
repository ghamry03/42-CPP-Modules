#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor is called" << std::endl;
}

WrongCat::WrongCat( std::string const & type ) : WrongAnimal(type) {
    std::cout << "WrongCat constructor is called" << std::endl;
}

WrongCat::~WrongCat( void ) {
    std::cout << "WrongCat destructor is called" << std::endl;
}

WrongCat::WrongCat( WrongCat const & copy ) : WrongAnimal(copy) {
    std::cout << "WrongCat copy constructor is called" << std::endl;
    *this = copy;
}

WrongCat & WrongCat::operator=( WrongCat const & copy ) {
    std::cout << "WrongCat copy assignment operator is called" << std::endl;
    WrongAnimal::operator=(copy);
    return ( *this );
}

void WrongCat::makeSound( void ) const {
    std::cout << "Meoww!?" << std::endl;
}
