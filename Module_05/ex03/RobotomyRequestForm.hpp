#ifndef ROBOTOMYREQUESTFORM_HPP 
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
                                                  RobotomyRequestForm(void);
                            RobotomyRequestForm(const std::string & target);
                                                 ~RobotomyRequestForm(void);
                      RobotomyRequestForm(const RobotomyRequestForm & copy);
          RobotomyRequestForm & operator=(const RobotomyRequestForm & copy);

                                  void execute(const Bureaucrat & executor);
};

#endif

