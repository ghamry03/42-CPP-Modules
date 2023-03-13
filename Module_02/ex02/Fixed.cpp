#include "Fixed.hpp"

Fixed::Fixed( void ) {
    this->setRawBits( 0 );
}

Fixed::Fixed( Fixed const& copy ) {
    *this = copy;
}

Fixed::Fixed( const int num ) {
    this->setRawBits( num << _bitsNum );
}

Fixed::Fixed( const float num ) {
    this->setRawBits( (int)round( num * ( 1 << _bitsNum ) ));
}

Fixed::~Fixed( void ) {
}

Fixed&          Fixed::operator=( Fixed const& copy ) {
    this->_num = copy.getRawBits();
    return ( *this );
}

Fixed          Fixed::operator+( Fixed const& copy ) const {
    return ( Fixed( this->toFloat() + copy.toFloat() ));
}

Fixed          Fixed::operator-( Fixed const& copy ) const {
    return ( Fixed( this->toFloat() - copy.toFloat() ));
}

Fixed          Fixed::operator*( Fixed const& copy ) const {
    return ( Fixed( this->toFloat() * copy.toFloat() ));
}

Fixed          Fixed::operator/( Fixed const& copy ) const {
    return ( Fixed( this->toFloat() / copy.toFloat() ));
}

bool           Fixed::operator>( Fixed const& copy ) const {
    return ( this->toFloat() > copy.toFloat() );
}

bool           Fixed::operator<( Fixed const& copy ) const {
    return ( this->toFloat() < copy.toFloat() );
}

bool           Fixed::operator>=( Fixed const& copy ) const {
    return ( this->toFloat() >= copy.toFloat() );
}

bool           Fixed::operator<=( Fixed const& copy ) const {
    return ( this->toFloat() <= copy.toFloat() );
}

bool           Fixed::operator==( Fixed const& copy ) const {
    return ( this->toFloat() == copy.toFloat() );
}

bool           Fixed::operator!=( Fixed const& copy ) const {
    return ( this->toFloat() != copy.toFloat() );
}

Fixed          Fixed::operator++( void ) {
    Fixed   ret;

    this->_num++;
    // this->_num = ( this->toFloat() + 1 ) * ( 1 << _bitsNum );
    ret.setRawBits( this->getRawBits() );
    return ( ret );
}

Fixed          Fixed::operator++( int num ) {
    Fixed   ret;

    (void)num;
    ret.setRawBits( this->getRawBits() );
    this->_num++;
    // this->_num = ( this->toFloat() + 1 ) * ( 1 << _bitsNum );
    return ( ret );
}

Fixed          Fixed::operator--( void ) {
    Fixed   ret;

    this->_num--;
    // this->_num = ( this->toFloat() - 1 ) * ( 1 << _bitsNum );
    ret.setRawBits( this->getRawBits() );
    return ( ret );
}

Fixed          Fixed::operator--( int num ) {
    Fixed   ret;

    (void)num;
    ret.setRawBits( this->getRawBits() );
    this->_num--;
    // this->_num = ( this->toFloat() - 1 ) * ( 1 << _bitsNum );
    return ( ret );
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

Fixed&          Fixed::min( Fixed& a, Fixed& b ) {
    return ( a < b ? a : b );
}

const Fixed&    Fixed::min( const Fixed& a, const Fixed& b ) {
    return ( a < b ? a : b );
}

Fixed&          Fixed::max( Fixed& a, Fixed& b ) {
    return ( a > b ? a : b );
}

const Fixed&    Fixed::max( const Fixed& a, const Fixed& b ) {
    return ( a > b ? a : b );
}

std::ostream&   operator<<( std::ostream& stream, Fixed const& fixed ) {
    stream << fixed.toFloat();
    return ( stream );
}
