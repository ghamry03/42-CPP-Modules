#include "AForm.hpp"

AForm::AForm(void)
    : _name ("default"), _isSigned(false), _signGrade(1), _execGrade(1) {
    std::cout << "Form defualt constructor is called" << std::endl;
}

AForm::AForm(const std::string & name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    this->_checkGrade(signGrade, grade);
    this->_checkGrade(execGrade, grade);
}

AForm::~AForm(void) {
    std::cout << "Form destructor is called" << std::endl;
}

AForm::AForm(const AForm & copy)
    :  _name(copy.getName()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {
    std::cout << "Form copy constructor is called" << std::endl;
    *this = copy;
}

AForm & AForm::operator=(const AForm & copy) {
    std::cout << "Form copy assignment operator is called" << std::endl;
    this->_isSigned = copy.getIsSigned();
    return (*this);
}

void                AForm::_checkGrade(int grade, gradeType type) {
    if (grade < 1)
        throw AForm::GradeTooHighException();
    else if (grade > 150)
        throw AForm::GradeTooLowException();
    if (type == signGrade && grade > this->getSignGrade()) {
        std::cout << "-------------" << _signGrade << "-" << grade << std::endl;
        throw AForm::GradeTooLowException();
    }
    else if (type == execGrade && grade > this->getExecGrade()) 
        throw AForm::GradeTooLowException();
}

void                AForm::beSigned(const Bureaucrat & bureaucrat) {
    if (this->getIsSigned()) 
        throw AForm::FormIsSignedException();

    this->_checkGrade(bureaucrat.getGrade(), signGrade);

    std::cout << bureaucrat.getName() << " signed form "
        << this->getName() << std::endl;
    this->_isSigned = true;
}

const std::string   AForm::getName(void) const {
    return (this->_name);
}

bool                AForm::getIsSigned(void) const {
    return (this->_isSigned);
}

const int &         AForm::getSignGrade(void) const {
    return (this->_signGrade);
}

const int &         AForm::getExecGrade(void) const {
    return (this->_execGrade);
}

const char *        AForm::GradeTooHighException::what(void) const throw() {
    return ("Grade too high");
}

const char *        AForm::GradeTooLowException::what(void) const throw() {
    return ("Grade too low");
}

const char *        AForm::FormIsSignedException::what(void) const throw() {
    return ("Form is already signed");
}

const char *        AForm::FormIsNotSignedException::what(void) const throw() {
    return ("Form isn't signed yet");
}

std::ostream & operator<<(std::ostream & stream, const AForm & form) {
    std::string     formState;

    formState = form.getIsSigned() == true ? ", form is signed"
                                  : ", form is not signed yet";
    stream << form.getName() << formState << " - [sign grade : "
        << form.getSignGrade() << " - exec grade "
        << form.getExecGrade() << "]";
    return (stream);
}
