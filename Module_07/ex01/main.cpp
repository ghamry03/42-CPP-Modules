#include <cctype>
#include "iter.hpp"

void    ft_checkNum( int const & num ) {
    if ( num % 2 == 0 )
        std::cout << num << " is even" << std::endl;
    else
        std::cout << num << " is odd" << std::endl;
}

int main(void) {
    std::cout << std::endl << std::endl;
    int test[4] = { 69, 420, 360, -123 };
    iter( test, 4, &ft_checkNum );
}
