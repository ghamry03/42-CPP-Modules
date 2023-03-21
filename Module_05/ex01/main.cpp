#include "Bureaucrat.hpp"

int main( void ) {
    {
        try {
            Bureaucrat  test("Baty5a", 9);
            Form        form("Far5a", 70, 1);

            std::cout << std::endl;

            try { 
                std::cout << test << std::endl;
                test.decGrade();
            } catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }

            std::cout << std::endl;

            try {
                test.signForm(form);
                form.beSigned(test);
            } catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }

            std::cout << std::endl;

        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
}
