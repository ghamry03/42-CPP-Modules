#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource( void ) {
}

IMateriaSource::~IMateriaSource( void ) {
}

IMateriaSource::IMateriaSource( IMateriaSource const & copy ) {
    *this = copy;
}

IMateriaSource & IMateriaSource::operator=( IMateriaSource const & copy ) {
    (void)copy;
    return ( *this );
}

