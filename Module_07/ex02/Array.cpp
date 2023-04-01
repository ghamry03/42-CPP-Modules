#include "Array.hpp"

template< typename T >
Array< T >::Array( void ) {
    std::cout << "Array default constructor is called" << std::endl; 
}

template< typename T >
Array< T >::Array( unsigned int n ) {
    std::cout << "Array constructor is callled" << std::endl;
    this->_array = new T [n];
}
