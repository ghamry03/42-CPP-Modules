#include <cctype>
#include "iter.hpp"

void    ft_toUpper( char & c ) {
    c = c >= 'a' && c <= 'z' ? c -= 32 : c;
}

void    ft_checkNum( int & num ) {
    if ( num % 2 == 0 )
        std::cout << num << " is even" << std::endl;
    else
        std::cout << num << " is odd" << std::endl;
}

int main(void) {
    // std::string test = "abcdef";
    // iter( test.c_str(), test.length(), &ft_toUpper );

    char test1[4] = "abc";
    std::cout << "Before: " << test1 << std::endl;
    iter( test1, 2, &ft_toUpper );
    std::cout << "After: " << test1 << std::endl;

    std::cout << std::endl << std::endl;
    int test2[4] = { 69, 420, 360, -123 };
    iter( test2, 4, &ft_checkNum );

    std::cout << std::endl << "printInputEndl" << std::endl;
    iter( test1, 3, &printInputEndl );
}
