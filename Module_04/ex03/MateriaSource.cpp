#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _materiaCount( 0 ) {
    for ( int i = 0; i < 4; i++ )
        _items[i] = NULL;
}

MateriaSource::~MateriaSource( void ) {
    for ( int i = 0; i < 4; i++ )
        if ( _items[i] )
            delete _items[i];
}

MateriaSource::MateriaSource( const MateriaSource & copy ) {
    *this = copy;
}

MateriaSource & MateriaSource::operator=( const MateriaSource & copy ) {
    for ( int i = 0; i < 4; i++ ) {
        if ( _items[i] )
            _items[i] = copy._items[i]->clone();
    }
    _materiaCount = copy._materiaCount;
    return ( *this );
}

void    MateriaSource::learnMateria( AMateria * m ) {
    if ( _materiaCount == 4 ) {
        std::cout << "Materia Source has the maximum amount of items" << std::endl;
        return ;
    }
    std::cout << "Materia Source learned new materia " << m->getType() << std::endl;
    _items[ _materiaCount ] = m->clone();
    _materiaCount++;
}

AMateria * MateriaSource::createMateria( std::string const & type ) {
    for (int i = 0; i < 4; i++) {
        if ( _items[i] && _items[i]->getType() == type )
            return ( this->_items[i] );
    }
    std::cout << "Material Source can't find " << type << std::endl;
    return (NULL);
}
