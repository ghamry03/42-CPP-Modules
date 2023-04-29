#include "Bureaucrat.hpp"

int main( void ) {
    try {
        Bureaucrat  test("Baty5a", 70);
        Form        form("Far5a", 69, 1);

        std::cout << std::endl;
        std::cout << test << std::endl;
        std::cout << form << std::endl;
        std::cout << std::endl;

        try {
            form.beSigned(test);
        } catch (std::exception & e) {
            std::cout << "Form error: [" << e.what() << "]" << std::endl;
        }

        std::cout << std::endl;

        try {
            test.signForm(form);
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }

        test.incGrade();
        test.signForm(form);

        std::cout << std::endl;
        std::cout << test << std::endl;
        std::cout << form << std::endl;
        std::cout << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}
