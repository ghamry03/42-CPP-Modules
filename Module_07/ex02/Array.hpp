#pragma once

#include <exception>
#include <iostream>

template < typename T >
class Array {
    private:
        T * _array;
        unsigned int _size;

    public:
        Array( void ) : _array( NULL ), _size( 0 ) {
            std::cout << "Array default constructor is called" << std::endl;
        }

        Array( const unsigned int & size ) : _size( size ){
            std::cout << "Array constructor is called" << std::endl;
            this->setArray( new T [_size]() );
        }

        Array( const Array & copy ) {
            std::cout << "Array copy constructor is called" << std::endl;
            *this = copy;
        }

        ~Array( void ) {
            std::cout << "Array destructor is called" << std::endl;
            if ( this->_array )
                delete [] this->_array;
        }

        Array & operator=( const Array & copy ) {
            std::cout << "Array copy assignment operator is called" << std::endl;
            this->setArray( copy.getArray() );
            return ( *this );
        }

        T & operator[]( unsigned int idx ) {
            if ( idx >= _size )
                throw InvalidIndexException();
            return ( this->getArray()[idx] );
        }

        T * getArray( void ) const {
            return ( this->_array );
        }

        unsigned int getSize( void ) const {
            return ( this->_size );
        }

        void setArray( T * array ) {
            this->_array = array;
        }

        class InvalidIndexException : public std::exception {
            public:
                virtual const char * what( void ) const throw() {
                    return ( "[Error: Invalid index]" );
                }
        };
};
