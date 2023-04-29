#include "Form.hpp"

Form::Form(void)
    : _name ("default"), _isSigned(false), _signGrade(1), _execGrade(1) {
    std::cout << "Form defualt constructor is called" << std::endl;
}

Form::Form(const std::string & name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    this->_checkGrade(signGrade);
    this->_checkGrade(execGrade);
}

Form::~Form(void) {
    std::cout << "Form destructor is called" << std::endl;
}

Form::Form(const Form & copy)
    :  _name(copy.getName()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {
    std::cout << "Form copy constructor is called" << std::endl;
    *this = copy;
}

Form & Form::operator=(const Form & copy) {
    std::cout << "Form copy assignment operator is called" << std::endl;
    this->_isSigned = copy.getIsSigned();
    return (*this);
}

void                Form::_checkGrade(int grade) {
    if (grade < 1)
        throw Form::GradeTooHighException();
    else if (grade > 150)
        throw Form::GradeTooLowException();
}

void                Form::beSigned(const Bureaucrat & bureaucrat) {
    if (this->getIsSigned()) 
        throw Form::FormIsSignedException();

    this->_checkGrade(bureaucrat.getGrade());

    if (bureaucrat.getGrade() > this->getSignGrade()) 
        throw Form::GradeTooLowException();

    std::cout << bureaucrat.getName() << " signed form "
        << this->getName() << std::endl;
    this->_isSigned = true;
}

const std::string   Form::getName(void) const {
    return (this->_name);
}

bool                Form::getIsSigned(void) const {
    return (this->_isSigned);
}

const int &         Form::getSignGrade(void) const {
    return (this->_signGrade);
}

const int &         Form::getExecGrade(void) const {
    return (this->_execGrade);
}

const char *        Form::GradeTooHighException::what(void) const throw() {
    return ("Grade too high");
}

const char *        Form::GradeTooLowException::what(void) const throw() {
    return ("Grade too low");
}

const char *        Form::FormIsSignedException::what(void) const throw() {
    return ("Form is already signed");
}

std::ostream & operator<<(std::ostream & stream, const Form & form) {
    std::string     formState;

    formState = form.getIsSigned() == true ? ", form is signed"
                                  : ", form is not signed yet";
    stream << form.getName() << formState << " - [sign grade : "
        << form.getSignGrade() << " - exec grade "
        << form.getExecGrade() << "]";
    return (stream);
}
