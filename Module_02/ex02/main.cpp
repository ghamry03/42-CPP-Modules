#include "Fixed.hpp"
#include <sstream>

std::string     floatToString( float num ) {
    std::ostringstream      ss;

    ss << num;
    return ( ss.str() );
}

std::string    fixString( std::string str ) {
    int            len;

    len = str.length();
    if (len > 10) {
        str.resize(9);
        str.append(".");
    }
    else if (len < 10) {
        str.insert(0, 10 - len, ' ');
    }
    return (str);
}

std::string    fixString( float num ) {
    int             len;
    std::string     str;

    str = floatToString( num );
    len = str.length();
    if (len > 10) {
        str.resize(9);
        str.append(".");
    }
    else if (len < 10) {
        str.insert(0, 10 - len, ' ');
    }
    return (str);
}

void    printTestCase( std::string testCase, Fixed a, Fixed b, Fixed c ) {
    std::cout << "|" << fixString( testCase ) << "|" << fixString( a.toFloat() )
        << "|" << fixString( b.toFloat() ) << "|" << fixString( c.toFloat() ) << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void    printTestCase( std::string testCase, Fixed a, Fixed b, std::string res ) {
    std::cout << "|" << fixString( testCase ) << "|" << fixString( a.toFloat() )
        << "|" << fixString( b.toFloat() ) << "|" << fixString( res ) << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void    arthmeticTestCases( void ) {
    Fixed   a( 1 );
    Fixed   b( 1.5f );
    Fixed   c;

    printTestCase( "init", a, b, c );
    c = a;
    printTestCase( "c = a", a, b, c );
    c = a + b;
    printTestCase( "c = a + b", a, b, c );
    c = a - b;
    printTestCase( "c = a - b", a, b, c );
    c = a * b;
    printTestCase( "c = a * b", a, b, c );
    c = a / b;
    printTestCase( "c = a / b", a, b, c );
    c = a + b;
    printTestCase( "c = a + b", a, b, c );
    c = a++;
    printTestCase( "c = a++", a, b, c );
    c = ++a;
    printTestCase( "c = ++a", a, b, c );
    c = a--;
    printTestCase( "c = a--", a, b, c );
    c = --a;
    printTestCase( "c = --a", a, b, c );
}

void    boolenTestCases( void ) {
    Fixed       a( 1 );
    Fixed       b( 1.5f );
    std::string  res;

    res = a < b ? "True" : "False";
    printTestCase( "a < b", a, b, res);

    res = a > b ? "True" : "False";
    printTestCase( "a > b", a, b, res);

    res = a <= b ? "True" : "False";
    printTestCase( "a <= b", a, b, res);

    res = a >= b ? "True" : "False";
    printTestCase( "a >= b", a, b, res);

    res = a == b ? "True" : "False";
    printTestCase( "a == b", a, b, res);
    res = a != b ? "True" : "False";
    printTestCase( "a != b", a, b, res);
}

void    memberFunctions( void ) {
    Fixed       a( 1 );
    Fixed       b( 1.5f );

    printTestCase( "min", a, b, Fixed::min( a, b ) );
    printTestCase( "max", a, b, Fixed::max( a, b ) );
}

int    main( void ) {
    {
        std::cout << " ___________________________________________ " << std::endl;
        std::cout << "|" << fixString( "test case" ) << "|" << fixString( "a" )
            << "|" << fixString( "b" ) << "|" << fixString( "result" ) << "|" << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
        arthmeticTestCases();
        boolenTestCases();
        memberFunctions();
        std::cout << std::endl;
    }
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }
}

