#include "Bureaucrat.hpp"

void gradeTest( void ) {
    Bureaucrat test("name", 150);

    std::cout << std::endl << test << std::endl;

    // grade too low exception
    try { 
        test.decGrade();
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << test << std::endl;

    // grade too high exception
    try {
        for ( int i = 0; i < 200; i++ ) {
            test.incGrade();
        }
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << test << std::endl;

    // grade too low exception
    try {
        for ( int i = 0; i < 200; i++ ) {
            test.decGrade();
        }
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << test << std::endl;
}

void constructorGradeTest( void ) {
    try {
        Bureaucrat( "test", -1 );
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat( "test", 151 );
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        int x = 69;
        int const & y = x;

        std::string s = "bruh";
        std::string const & sc = s;

        Bureaucrat( s, x );
        Bureaucrat( sc, y );
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }
}

int main( void ) {
    gradeTest();
    std::cout << std::endl;
    constructorGradeTest();
}
