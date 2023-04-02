#include "Span.hpp"

int main( void ) { 
    {
        Span sp = Span(5);
        try {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            sp.addNumber(11);
        } catch ( std::exception & e ) {
            std::cout << e.what() << std::endl;
        }
        sp.printSpan();
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
}
