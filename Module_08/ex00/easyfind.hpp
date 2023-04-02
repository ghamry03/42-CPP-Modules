#pragma once

#include <iostream>
#include <exception>
#include <iterator>
#include <algorithm>

class notFoundException : public std::exception {
    virtual const char * what( void ) const throw() {
        return ( "[can't find number]" );
    }
};

template< typename T >
typename T::iterator easyFind( T & input, int num ) {
    typename T::iterator it;

    it = std::find( input.begin(), input.end(), num );
    if ( it == input.end() )
        throw notFoundException();
    return ( it );
}
