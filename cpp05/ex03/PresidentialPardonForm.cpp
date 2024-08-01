#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
};
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
}
PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &temp) : AForm(temp) {
}

const std::string &PresidentialPardonForm::getTarget() const {
    return target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &temp) {
    AForm::operator=(temp);
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executer) const
{
    isExecuteable(executer);
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}