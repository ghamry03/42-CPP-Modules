#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string                                 _name;
        bool                                          _isSigned;
        const int                                    _signGrade;
        const int                                    _execGrade;
        
        void                             _checkGrade(int grade);

    public:
                                                   Form(void);
                                                  ~Form(void);
                Form(const std::string & name, int signGrade,
                                               int execGrade);
                                      Form(const Form & copy);
                          Form & operator=(const Form & copy);

        void          beSigned(const Bureaucrat & bureaucrat);

        const std::string                 getName(void) const;
        bool                          getIsSigned(void) const;
        const int &                  getSignGrade(void) const;
        const int &                  getExecGrade(void) const;

        class  GradeTooHighException : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };

        class  GradeTooLowException : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };

        class FormIsSignedException : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };
};

std::ostream & operator<<(std::ostream & stream, 
                                      const Form & form);

#endif

