#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
#include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {
    private:
        std::string _name;
        int         _materiaCount;
        AMateria *  _items[4];
        bool        _isEquiped[4];

    public:
        Character( void );
        Character( std::string const & name );
        ~Character( void );
        Character( const Character & copy );
        Character & operator=( const Character & copy );

        std::string const & getName( void ) const;

        void    equip( AMateria * m );
        void    unequip( int idx );
        void    use( int idx, ICharacter & target );
};

#endif
