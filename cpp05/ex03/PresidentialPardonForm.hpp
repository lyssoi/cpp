#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &temp);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &temp);
    PresidentialPardonForm(const std::string &name);
    void execute(const Bureaucrat &executer) const;
};
#endif