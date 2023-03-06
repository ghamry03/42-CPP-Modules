#include "Point.hpp"

Point::Point( void ) : _x( 0 ), _y( 0 ) {}

Point::Point( Point const& copy ) { *this = copy; }

Point::Point( float const x, float const y ) : _x( x ), _y( y ) {}

Point&  Point::operator=( Point const & copy ) {
    this->_x = copy._x;
    this->_y = copy._y;
    return ( *this );
}

Point::~Point( void ) {}

Fixed   Point::getX( void ) const {
    return ( this->_x );
}

Fixed   Point::getY( void ) const {
    return ( this->_y );
}
