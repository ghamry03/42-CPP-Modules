#ifndef PRESIDENTIALPARDONFORM_HPP 
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
                                                   PresidentialPardonForm(void);
                             PresidentialPardonForm(const std::string & target);
                                                  ~PresidentialPardonForm(void);
                    PresidentialPardonForm(const PresidentialPardonForm & copy);
        PresidentialPardonForm & operator=(const PresidentialPardonForm & copy);

                                      void execute(const Bureaucrat & executor);
};

#endif

