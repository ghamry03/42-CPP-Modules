#include "DiamondTrap.hpp"

int main( void ) {
    DiamondTrap a( "DiamondA" );
    const DiamondTrap b( "DiamondB" );
    DiamondTrap c(a);

    std::cout << std::endl;

    a.wohAmI();
    b.wohAmI();
    c.wohAmI();

    std::cout << std::endl;

    a.attack("bruv");

    std::cout << std::endl;

    return 1;
}
