#pragma once

#include <exception>
#include <iostream>

template <typename T>
class Array {
    private:
                T * _array;
        unsigned int _size;

    public:
        Array( void ) : _size( 0 ) { 
            std::cout << "Array default constructor is called" << std::endl;
            this->_array = new T[0];
        }

        Array( const unsigned int & size ) : _size( size ){
            std::cout << "Array constructor is called" << std::endl;
            this->_array = new T[_size];
        }

        Array( const Array & copy ) {
            std::cout << "Array copy constructor is called" << std::endl;
            this->_array = NULL;
            *this = copy;
        }

        ~Array( void ) {
            std::cout << "Array destructor is called" << std::endl;
            if ( this->_array )
                delete [] this->_array;
        }

        Array & operator=( const Array & copy ) {
            std::cout << "Array copy assignment operator is called" << std::endl;

            if ( this->_array )
                delete [] this->_array;

            this->_array = new T [ copy.size() ];
            for ( unsigned int i = 0; i < copy.size(); i++ ) {
                this->_array[i] = copy._array[i];
            }
            this->_size = copy.size();

            return ( *this );
        }

        T & operator[]( unsigned int idx ) {
            if ( idx >= _size )
                throw InvalidIndexException();
            return ( this->_array[idx] );
        }

        unsigned int size( void ) const {
            return ( this->_size );
        }

        class InvalidIndexException : public std::exception {
            public:
                virtual const char * what( void ) const throw() {
                    return ( "[Error: Invalid index]" );
                }
        };
};
