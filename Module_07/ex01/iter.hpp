#pragma once

#include <iostream>

template< typename T >
void    printInputEndl( T & input ) {
    std::cout << input << std::endl;
}

template< typename T >
void    iter( T * array, size_t arrayLength, void (*f)( T & ) ) {
    if ( !array || !f )
        return ;
    for ( size_t i = 0; i < arrayLength; i++ )
        (f)( array[i] );
}

