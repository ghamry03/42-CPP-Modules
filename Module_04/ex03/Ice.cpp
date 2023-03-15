#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
}

Ice::~Ice( void ) {
}

Ice::Ice( Ice const & copy ) : AMateria(copy) {
    *this = copy;
}

Ice & Ice::operator=( Ice const & copy ) {
    this->AMateria::operator=(copy);
    return (*this);
}

Ice * Ice::clone( void ) const {
    Ice * ret = new Ice( *this);
    return(ret);
}

void    Ice::use(ICharacter & target) {
    std::cout << "shoots an ice bolt at " << target.getName() << std::endl;
}
