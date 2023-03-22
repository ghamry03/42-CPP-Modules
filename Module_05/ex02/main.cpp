#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void    shrubberyTests(void) {
    std::cout << "----------" << std::endl;
    try {
        Bureaucrat  test("Baty5a", 138);
        ShrubberyCreationForm form("Far5a");

        std::cout << std::endl;
        std::cout << form << std::endl;
        std::cout << std::endl;

        form.execute(test);

        try {
            form.beSigned(test);
        } catch (std::exception & e) {
            std::cout << "Signing form Failed [" << e.what() << "]" << std::endl;
        }

        test.incGrade();
        std::cout << test << std::endl;
        test.signForm(form);

        form.execute(test);
        std::cout << std::endl;
        
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------" << std::endl;
}

int main(void) {
    shrubberyTests();
}
