#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

enum    gradeType {
    grade,
    signGrade,
    execGrade,
};

class AForm {
    protected:
        const std::string                               _name;
        bool _isSigned;
        const int                                  _signGrade;
        const int                                  _execGrade;

        void           _checkGrade(int grade, gradeType type);

    public:
                                                  AForm(void);
                                                 ~AForm(void);
                AForm(const std::string & name, int signGrade,
                                               int execGrade);
                                    AForm(const AForm & copy);
                        AForm & operator=(const AForm & copy);

        void          beSigned(const Bureaucrat & bureaucrat);
        virtual void execute(const Bureaucrat & executor) = 0;

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

        class FormIsNotSignedException : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };
};

std::ostream & operator<<(std::ostream & stream, 
                                      const AForm & form);

#endif

