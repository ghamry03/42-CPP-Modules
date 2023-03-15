#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter {
    private:
        int             _itemsCount;
        AMateria    *   _items[4];
        std::string     _name;


    public:
        Character( void );
        Character( std::string const & name );
        ~Character( void );
        Character( Character const & copy );
        Character & operator=( Character const & copy );

        std::string const & getName( void ) const;
        void                equip(AMateria * m);
        void                unequip(int idx);
        void                use(int idx, ICharacter & target);

};

#endif
