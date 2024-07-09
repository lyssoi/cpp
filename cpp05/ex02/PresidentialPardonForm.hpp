#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm(const string &name);
    void execute(const Bureaucrat &executer) const;
};
#endif