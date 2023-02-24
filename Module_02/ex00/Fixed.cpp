#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits( 0 ) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed& copy ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed&  Fixed::operator=( Fixed const& copy ) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rawBits = copy.getRawBits();
    return ( *this );
}

int     Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return ( this->_rawBits );
}

void    Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}
