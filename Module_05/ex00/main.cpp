#include "Bureaucrat.hpp"

int main( void ) {
    {
        Bureaucrat test("aaa", 150);

        try { 
            std::cout << test << std::endl;
            test.decGrade();
        }
        catch ( std::exception & e ) {
            std::cout << e.what() << std::endl;
        }
    }
}
