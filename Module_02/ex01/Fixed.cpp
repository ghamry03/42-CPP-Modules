#include "Fixed.hpp"

Fixed::Fixed( void ) : _num( 0 ) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& copy ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed( const int num ) {
    this->_num = num << _bitsNum;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) {
    this->_num = round( num * ( 1 << _bitsNum ) );
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

Fixed&          Fixed::operator=( Fixed const& copy ) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_num = copy.getRawBits();
    return ( *this );
}

int             Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return ( this->_num );
}

void            Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_num = raw;
}

int              Fixed::toInt( void ) const {
    return ( this->_num >> _bitsNum );
}

float           Fixed::toFloat( void ) const {
    return ( (float)this->_num / ( 1 << _bitsNum ) );
}

std::ostream&   operator<<( std::ostream& stream, Fixed const& fixed ) {
    stream << fixed.toFloat();
    return ( stream );
}
