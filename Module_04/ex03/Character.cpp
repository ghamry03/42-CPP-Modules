#include "Character.hpp"

Character::Character( void ) : _itemsCount(0), _name("default character") {
    std::cout << "Character default constructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_items[i] = NULL;
}

Character::Character( std::string const & name ) : _itemsCount(0), _name(name) {
    std::cout << "Character constructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_items[i] = NULL;
}

Character::~Character( void ) {
    std::cout << "Character destructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        delete this->_items[i];
}

Character::Character( Character const & copy ) : ICharacter(copy), _name(copy.getName()) {
    std::cout << "Character copy constructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_items[i] = NULL;
    *this = copy;
}

Character & Character::operator=( Character const & copy ) {
    std::cout << "Character copy assignment operator is called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_items[i])
            this->_items[i] = copy._items[i]->clone();
    this->_itemsCount = copy._itemsCount;
    this->_name = copy.getName();
    return (*this);
}

std::string const & Character::getName( void ) const {
    return (this->_name);
}

void    Character::equip(AMateria * m) {
    if (this->_itemsCount == 4)
        std::cout << "Character inventory is full" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (!this->_items[i]) {
            std::cout << "Item picked item at index " << i << std::endl;
            this->_items[i] = m;
            this->_itemsCount++;
            break ;
        }
    }
}

void    Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        std::cout << "invalid index" << std::endl;
    else if (!this->_items[idx]) {
        std::cout << "Character doesn't have item at index " << idx << std::endl;
    } else {
        std::cout << "Character dropped item " << idx << std::endl;
        this->_itemsCount--;
        delete this->_items[idx];
        this->_items[idx] = NULL;
    }
}

void    Character::use(int idx, ICharacter & target) {
    if (idx < 0 || idx > 3)
        std::cout << "invalid index" << std::endl;
    else if (!this->_items[idx])
        std::cout << "Character doesn't have an item at index " << idx << std::endl;
    else
        this->_items[idx]->use(target);
}
