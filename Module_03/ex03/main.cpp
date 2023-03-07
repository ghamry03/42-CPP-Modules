#include "DiamondTrap.hpp"

int main( void ) {
    DiamondTrap a("hamada");
    std::cout << "--------------------------------------------" << std::endl;
    a.wohAmI();
    a.attack("mr confused");
    std::cout << std::endl
              << "--------------------------------------------" << std::endl;
    return 1;
}
