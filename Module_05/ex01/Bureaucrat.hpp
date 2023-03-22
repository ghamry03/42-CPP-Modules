#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string                                 _name;
        int                                              _grade;
        void                             _setGrade(int grade);

    public:
                                             Bureaucrat(void);
                                            ~Bureaucrat(void);
                          Bureaucrat(const Bureaucrat & copy);
                      Bureaucrat(std::string name, int grade);
        Bureaucrat &       operator=(const Bureaucrat & copy);

        int                              getGrade(void) const;
        const std::string                getName(void)  const;

        void                                   incGrade(void);
        void                                   decGrade(void);
        void                      signForm(Form & form) const;

        class  GradeTooHighException : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };

        class  GradeTooLowException : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };
};

std::ostream & operator<<(std::ostream & stream, 
                                const Bureaucrat & bureaucrat);

#endif
