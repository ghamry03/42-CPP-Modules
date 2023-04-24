#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main( void )
{
    IMateriaSource* src = new MateriaSource();
    AMateria * ice = new Ice();
    AMateria * cure = new Cure();
    src->learnMateria(ice);
    src->learnMateria(cure);
    delete ice;
    delete cure;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->unequip(0);
    me->equip(tmp);
    me->use(0, *bob);
    delete bob;
    delete me;
    delete src;
}
