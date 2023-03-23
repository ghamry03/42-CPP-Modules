#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    private:
        AForm *                      _makeShrubbery(const std::string & target);
        AForm *                       _makeRobotomy(const std::string & target);
        AForm *                   _makePresidential(const std::string & target);

    public:
                                                                   Intern(void);
                                                                  ~Intern(void);
                                                    Intern(const Intern & copy);
                                        Intern & operator=(const Intern & copy);

         AForm * makeForm(const std::string & name, const std::string & target);
};

#endif
