#include "Character.hpp"
#include "AMateria.hpp"

Character::Character( void ) : _name( "null" ), _materiaCount( 0 ) {
    for ( int i = 0; i < 4; i++ ) {
        _items[i] = NULL;
        _isEquiped[i] = false;
    }
}

Character::Character( std::string const & name ) : _name( name ), _materiaCount( 0 ) {
    for ( int i = 0; i < 4; i++ ) {
        _items[i] = NULL;
        _isEquiped[i] = false;
    }
}

Character::~Character( void ) {
    for ( int i = 0; i < 4; i++ )
        if ( _items[i] )
            delete _items[i];
}

Character::Character( const Character & copy ) : _name( copy.getName() ), _materiaCount( copy._materiaCount ) {
    *this = copy;
}

Character & Character::operator=( const Character & copy ) {
    for ( int i = 0; i < 4; i++ ) {
        if ( _items[i] )
            _items[i] = copy._items[i]->clone();
        _isEquiped[i] = copy._isEquiped[i];
    }
    _name = copy.getName();
    _materiaCount = copy._materiaCount;
    return ( *this );
}

std::string const & Character::getName( void ) const {
    return ( this->_name );
}

void Character::equip( AMateria * m ) {
    if ( _materiaCount == 4 ) {
        std::cout << "Character " << this->getName() << " inventory is full" << std::endl;
        return ;
    }
    for ( int i = 0; i < 4; i++ ) {
        if ( _isEquiped[i] == false ) {
            std::cout << "Character " << this->getName() << " equiped item "
                << m->getType() << " at index " << i << std::endl;
            if ( _items[i] )
                delete _items[i];
            _items[i] = m->clone();
            _isEquiped[i] = true;
            _materiaCount++;
            break ;
        } 
    }
}

void Character::unequip( int idx ) {
    if ( idx < 0 || idx > 3 )
        std::cout << "Error: invalid index" << std::endl;
    else if ( _isEquiped[idx] == false )
        std::cout << "Character " << this->getName()
            << " doesn't have an item at index" << idx << std::endl;
    else {
        std::cout << "Character " << this->getName()
            << " dropped an item at index " << idx << std::endl;
        _isEquiped[idx] = false;
        _materiaCount--;
    }
}

void Character::use( int idx, ICharacter & target ) {
    if ( idx < 0 || idx > 3 )
        std::cout << "Error: invalid index" << std::endl;
    else if ( _isEquiped[idx] == false )
        std::cout << "Character " << this->getName()
            << " doesn't have an item at index" << idx << std::endl;
    else
        _items[idx]->use( target );
}
