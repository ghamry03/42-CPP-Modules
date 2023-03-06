#include "bsp.hpp"

void    printBool ( bool ret ) {
    std::string retString = ret ? "Point is inside the triangle"
        : "Point isn't inside the triangle" ;
    std::cout << retString << std::endl;
}

int main( void ) {
    // trinagle ABC on graph
    // https://www.desmos.com/calculator/nuccy2gigg
    Point A(0, 0);
    Point B(4, 0);
    Point C(0, 10);
    printBool( bsp( A, B, C, Point(1, 1) ) ); // test 1
    printBool( bsp( A, B, C, Point(5, 5) ) ); // test 2
    printBool( bsp( A, B, C, Point(0, 3) ) ); // test 3
}
