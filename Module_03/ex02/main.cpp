#include "FragTrap.hpp"

int main( void ) {
    FragTrap * a = new FragTrap("huh");
    a->highFivesGuys();
    delete a;
    return 1;
}
