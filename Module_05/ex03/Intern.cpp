#include "Intern.hpp"

Intern::Intern(void) {
    std::cout << "Intern default constructor is called" << std::endl;
}

Intern::~Intern(void) {
    std::cout << "Intern destructor is called" << std::endl;
}

Intern::Intern(const Intern & copy) {
    std::cout << "Intern copy constructor is called" << std::endl;
    *this = copy;
}

Intern & Intern::operator=(const Intern & copy) {
    std::cout << "Intern copy assignment operator is called" << std::endl;
    (void)copy;
    return (*this);
}

AForm *     Intern::_makeShrubbery(const std::string & target) {
    return (new ShrubberyCreationForm(target));
}

AForm *     Intern::_makeRobotomy(const std::string & target) {
    return (new RobotomyRequestForm(target));
}

AForm *     Intern::_makePresidential(const std::string & target) {
    return (new PresidentialPardonForm(target));
}

AForm *     Intern::makeForm(const std::string & name, const std::string & target) {
    std::string formTypes[3] = {"shrubbery creation",
                "robotomy request", "presidential pardon"};

    AForm *     (Intern::*f[4])(const std::string & tar) = {&Intern::_makeShrubbery,
                &Intern::_makeRobotomy, &Intern::_makePresidential};

    for (int i = 0; i < 3; i++) {
        if (formTypes[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*f[i])(target);
        }
    }
    std::cout << "Intern couldn't find form " << name << std::endl;
    return (NULL);
}
