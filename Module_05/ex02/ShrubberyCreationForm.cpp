#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("default_shrubbery", 145, 137) {
    std::cout << "ShrubberyCreationForm defualt constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
    : AForm(target, 145, 137) {
    std::cout << "ShrubberyCreationForm defualt constructor is called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm destructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy) : AForm(copy) {
    std::cout << "ShrubberyCreationForm copy constructor is called" << std::endl;
    *this = copy;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & copy) {
    std::cout << "ShrubberyCreationForm copy assignment operator is called" << std::endl;
    AForm::operator=( copy );
    return (*this);
}

void    ShrubberyCreationForm::execute(const Bureaucrat & executor) {
    try {
        if (!this->getIsSigned()) 
            throw AForm::FormIsNotSignedException();
        this->_checkGrade(executor.getGrade(), execGrade);

        std::ofstream   outFile;
        outFile.open((this->getName()+ "_shrubbery").c_str());
        if (!outFile.is_open()) {
            std::cout << "Error: Failed to open file" << std::endl;
            return ;
        }
        outFile << ASCIITREE << std::endl;
        std::cout << executor.getName() << " executed "
            << this->getName() << std::endl;
    } catch (std::exception & e) {
        std::cout << "Bureaucrat " << executor.getName() << " can't execute "
            << this->getName() << " [" << e.what() << "]" << std::endl;
    }
}
