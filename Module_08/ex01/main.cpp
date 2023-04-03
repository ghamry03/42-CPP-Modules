#include "Span.hpp"

int main( void ) { 
    {
       Span sp = Span( 1000000 ); 
       try {
           sp.AddRandomNumbers( 10000000 );
        } catch ( std::exception & e ) {
            std::cout << e.what() << std::endl;
        }
        sp.printSpan();
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
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
    std::cout << std::endl;
    std::cout << std::endl;
    {
        std::vector< int >nums;
        nums.push_back(6);
        nums.push_back(3);
        nums.push_back(17);
        nums.push_back(9);
        nums.push_back(11);
        nums.push_back(11);
        std::vector< int >::iterator begin = nums.begin();
        std::vector< int >::iterator end = nums.end();

        Span sp( 5 );
        try {
            sp.AddIterNumbers( begin, end);
        } catch ( std::exception & e ) {
            std::cout << e.what() << std::endl;
        }
        sp.printSpan();
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
}
