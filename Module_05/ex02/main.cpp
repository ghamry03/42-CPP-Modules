#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    shrubberyCreationFormTests(void) {
    std::cout << "-----------------------------------------------" << std::endl;
    try {
        Bureaucrat            test("Baty5a", 138);
        ShrubberyCreationForm form("Far5a");

        std::cout << std::endl;
        std::cout << form << std::endl;
        std::cout << std::endl;

        test.executeForm(form);

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
    std::cout << "-----------------------------------------------" << std::endl;
}

void    RobotomyRequrestFormTests(void) {
    std::cout << "-----------------------------------------------" << std::endl;
    try {
        Bureaucrat          test("Baty5a", 42);
        RobotomyRequestForm form("Far5a");

        std::cout << std::endl;
        std::cout << form << std::endl;
        std::cout << std::endl;

        test.executeForm(form);

        try {
            form.beSigned(test);
        } catch (std::exception & e) {
            std::cout << "Signing form Failed [" << e.what() << "]" << std::endl;
        }

        test.incGrade();
        std::cout << test << std::endl;
        test.signForm(form);

        std::cout << std::endl;
        form.execute(test);
        std::cout << std::endl;
        
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
}

void    PresidentialPardonFormTests(void) {
    std::cout << "-----------------------------------------------" << std::endl;
    try {
        Bureaucrat              test("Baty5a", 6);
        PresidentialPardonForm  form("Far5a");

        std::cout << std::endl;
        std::cout << form << std::endl;
        std::cout << std::endl;

        test.executeForm(form);

        try {
            form.beSigned(test);
        } catch (std::exception & e) {
            std::cout << "Signing form Failed [" << e.what() << "]" << std::endl;
        }

        test.incGrade();
        std::cout << test << std::endl;
        test.signForm(form);

        std::cout << std::endl;
        form.execute(test);
        std::cout << std::endl;
        
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
}


int main(void) {
    shrubberyCreationFormTests();
    RobotomyRequrestFormTests();
    PresidentialPardonFormTests();
}
