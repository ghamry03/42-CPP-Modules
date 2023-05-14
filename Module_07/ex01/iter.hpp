#pragma once

#include <iostream>

template< typename T >
void    iter( T * array, size_t arrayLength, void (*f)( T const & ) ) {
    if ( !array || !f )
        return ;
    for ( size_t i = 0; i < arrayLength; i++ )
        (f)( array[i] );
}

