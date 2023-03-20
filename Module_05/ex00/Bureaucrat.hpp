#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
    private:
        std::string const                                 _name;
        int                                              _grade;
        void                             _setGrade( int grade );

    public:
                                             Bureaucrat( void );
                                            ~Bureaucrat( void );
                          Bureaucrat( Bureaucrat const & copy );
                      Bureaucrat( std::string name, int grade );
        Bureaucrat &       operator=( Bureaucrat const & copy );

        int                              getGrade( void ) const;
        std::string const                getName( void )  const;

        void                                   incGrade( void );
        void                                   decGrade( void );

        class  GradeTooHighException : public std::exception {
            public:
                virtual const char * what( void ) const throw();
        };

        class  GradeTooLowException : public std::exception {
            public:
                virtual const char * what( void ) const throw();
        };
};

std::ostream & operator<<( std::ostream & stream, 
                                Bureaucrat const & bureaucrat );

#endif
