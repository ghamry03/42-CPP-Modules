#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
    Intern      baqalaa;
    Bureaucrat  boss("boss", 1);

    AForm * shrubbery = baqalaa.makeForm("shrubbery creation", "baty5a");
    AForm * robotomy = baqalaa.makeForm("robotomy request", "tofa7aa");
    AForm * presidential = baqalaa.makeForm("presidential pardon", "far5a");
    baqalaa.makeForm("blahh", "idk");

    std::cout << std::endl << std::endl;

    boss.signForm(*shrubbery);
    boss.signForm(*robotomy);
    boss.signForm(*presidential);
 
    std::cout << std::endl << std::endl;

    shrubbery->execute(boss);
    robotomy->execute(boss);
    presidential->execute(boss);

    std::cout << std::endl << std::endl;

    delete shrubbery;
    delete robotomy;
    delete presidential;
}
