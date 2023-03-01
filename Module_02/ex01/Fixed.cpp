#include "Fixed.hpp"

Fixed::Fixed( void ) {
    this->setRawBits( 0 );
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& copy ) {
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( const int num ) {
    this->setRawBits( num << _bitsNum );
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) {
    this->setRawBits( round( num * ( 1 << _bitsNum ) ));
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
    return ( this->_num );
}

void            Fixed::setRawBits( int const raw ) {
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
