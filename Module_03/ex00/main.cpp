#include "ClapTrap.hpp"
#include <limits.h>

int main( void ) {
   ClapTrap first("first");
   ClapTrap second("second");

    first.attack("second");
    // second.takeDamage((unsigned int)INT_MAX + 2);
    second.takeDamage(99);
    second.attack("dasda");
    second.beRepaired(1);
    return ( 0 );
}
