#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("default_shrubbery", 25, 5) {
    std::cout << "PresidentialPardonForm defualt constructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
    : AForm(target, 25, 5) {
    std::cout << "PresidentialPardonForm defualt constructor is called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialPardonForm destructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy) : AForm(copy) {
    std::cout << "PresidentialPardonForm copy constructor is called" << std::endl;
    *this = copy;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & copy) {
    std::cout << "PresidentialPardonForm copy assignment operator is called" << std::endl;
    AForm::operator=( copy );
    return (*this);
}

void    PresidentialPardonForm::execute(const Bureaucrat & executor) {
    try {
        if (!this->getIsSigned()) 
            throw AForm::FormIsNotSignedException();
        this->_checkGrade(executor.getGrade(), execGrade);

        std::cout << executor.getName()
            << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    } catch (std::exception & e) {
        std::cout << "Bureaucrat " << executor.getName() << " can't execute "
            << this->getName() << " [" << e.what() << "]" << std::endl;
    }
}
