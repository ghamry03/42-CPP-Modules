#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        Fixed _x;
        Fixed _y;

    public:
        Point( void );
        Point( Point const& copy );
        Point( float const x, float const y );
        ~Point( void );

        Point & operator=( Point const & copy );

        Fixed   getX( void ) const;
        Fixed   getY( void ) const;
};

#endif
