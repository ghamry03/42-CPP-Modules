#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("default_shrubbery", 72, 45) {
    std::cout << "RobotomyRequestForm defualt constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
    : AForm(target, 72, 45) {
    std::cout << "RobotomyRequestForm defualt constructor is called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm destructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy) : AForm(copy) {
    std::cout << "RobotomyRequestForm copy constructor is called" << std::endl;
    *this = copy;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & copy) {
    std::cout << "RobotomyRequestForm copy assignment operator is called" << std::endl;
    AForm::operator=( copy );
    return (*this);
}

void    RobotomyRequestForm::execute(const Bureaucrat & executor) {
    try {
        if (!this->getIsSigned()) 
            throw AForm::FormIsNotSignedException();
        this->_checkGrade(executor.getGrade(), execGrade);

        std::cout << "**** DRILLING NOISE ****" << std::endl; 
        std::srand((unsigned int)(time(NULL)));
        if (std::rand() % 2)
            std::cout << executor.getName() << " has been robotomized successfully"
                << std::endl;
        else
            std::cout << executor.getName() << " robotomizing failed"
                << std::endl;
    } catch (std::exception & e) {
        std::cout << "Bureaucrat " << executor.getName() << " can't execute "
            << this->getName() << " [" << e.what() << "]" << std::endl;
    }
}
