#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(1) {
    std::cout << "Bureaucrat defualt constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int const & grade) : _name(name) {
    std::cout << "Bureaucrat constructor is called" << std::endl;
    _setGrade(grade);
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat destructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & copy) : _name(copy.getName()) {
    std::cout << "Bureaucrat copy constructor is called" << std::endl;
    *this = copy;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & copy) {
    std::cout << "Bureaucrat copy assignment operator is called" << std::endl;
    this->_grade = copy._grade;
    return (*this);
}

void                Bureaucrat::_setGrade(int grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

int                 Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

const std::string   Bureaucrat::getName(void) const {
    return (this->_name);
}

void                Bureaucrat::incGrade(void) {
    this->_setGrade(this->getGrade() - 1);
}

void                Bureaucrat::decGrade(void) {
    this->_setGrade(this->getGrade() + 1);
}

void                Bureaucrat::signForm(AForm & form) const {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed "
            << form.getName() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << this->getName() << " couldn't sign " << form.getName()
            << " because [" << e.what() << "]." << std::endl;
    }
}                             

void                Bureaucrat::executeForm(AForm & form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed "
            << form.getName() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << this->getName() << " couldn't execute " << form.getName()
            << " because [" << e.what() << "]." << std::endl;
    }
}

const char *        Bureaucrat::GradeTooHighException::what(void) const throw() {
    return ("Error: Grade Too High");
}

const char *        Bureaucrat::GradeTooLowException::what(void) const throw() {
    return ("Error: Grade Too Low");
}

std::ostream &      operator<<(std::ostream & stream, const Bureaucrat & bureaucrat) {
    stream << bureaucrat.getName() << ", bureaucrat grade "
        << bureaucrat.getGrade();
    return (stream);
}
