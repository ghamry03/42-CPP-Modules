#include "Span.hpp"

Span::Span( void ) : _max( 0 ) {
    std::cout << "Span default constructor is called" << std::endl;
}

Span::Span( unsigned int max ) : _max( max ) {
    std::cout << "Span constructor is called" << std::endl;
}

Span::~Span( void ) {
    std::cout << "Span destructor is called" << std::endl;
}

Span::Span( const Span & copy ) {
    std::cout << "Span copy constructor is called" << std::endl;
    *this = copy;
}

Span & Span::operator=( const Span & copy ) {
    std::cout << "Span copy assignment operator is called" << std::endl;
    this->_max = copy._max;
    this->_nums = copy._nums;
    return (*this);
}

void    Span::printSpan( void ) {
    std::vector< int >::iterator it;
    it = this->_nums.begin();
    
    std::cout << "span: ";
    for ( ; it != this->_nums.end(); it++ ) {
        std::cout << *it;
        if ( it != this->_nums.end() - 1 )
            std::cout << ", ";
    }
    std::cout << std::endl;
}

void    Span::addNumber( int num ) {
    if ( this->_nums.size() == this->_max ) 
        throw MaxElementsException();
    this->_nums.push_back( num );
}

int     Span::shortestSpan( void ) {
    if ( this->_nums.size() < 2 )
        throw NotEnoughElementsException();

    std::vector< int >::iterator min = std::min_element( _nums.begin(), _nums.end() );
    std::vector< int >::iterator max = std::max_element( _nums.begin(), _nums.end() );
    return ( *max - *min );
}

int     Span::longestSpan( void ) {
    if ( this->_nums.size() < 2 )
        throw NotEnoughElementsException();

    std::vector< int >::iterator min = std::min_element( _nums.begin(), _nums.end() );
    std::vector< int >::iterator max = std::max_element( _nums.begin(), _nums.end() );
    return ( *max - *min );
}

const char * Span::MaxElementsException::what( void ) const throw() {
    return ( "Span reached maximum amount of elements" );
}

const char * Span::NotEnoughElementsException::what( void ) const throw() {
    return ( "Span doesn't have enough elements" );
}
