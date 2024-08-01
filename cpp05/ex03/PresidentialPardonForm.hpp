#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
private:
    const std::string target;
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &temp);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &temp);
public:
    ~PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    const std::string &getTarget() const;
    void execute(const Bureaucrat &executer) const;
};
#endif