#include "Span.hpp"

void    randomNumbersTest( void ) {
    std::cout << "------------- 10000000 span size ------------- " << std::endl;
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
}

void    basicTest( void ) {
    std::cout << "------------- 5 span size ------------- " << std::endl;
    {
        Span sp = Span(5);
        try {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
        } catch ( std::exception & e ) {
            std::cout << e.what() << std::endl;
        }
        sp.printSpan();
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
}

void    AddUsingIterTest( void ) {
    std::cout << "------------- it 5 span size ------------- " << std::endl;
    {
        std::vector< int >nums;
        nums.push_back(6);
        nums.push_back(3);
        nums.push_back(17);
        nums.push_back(9);
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

void    errorMangmentTests( void ) {
    std::cout << "------------- error tests ------------- " << std::endl;
    {
        Span sp( 5 );
        for ( int i = 0; i < 6; i++ ) {
            try {
                std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
            } catch ( std::exception & e ) {
                std::cout << e.what() << std::endl;
            }
            try {
                sp.AddRandomNumbers( 1 );
            } catch ( std::exception & e ) {
                std::cout << e.what() << std::endl;
            }
            sp.printSpan();
        }
    }
}

int main( void ) { 
    randomNumbersTest();
    std::cout << std::endl;
    basicTest();
    std::cout << std::endl;
    AddUsingIterTest();
    std::cout << std::endl;
    errorMangmentTests();
}
