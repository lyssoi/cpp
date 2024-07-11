#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : AForm(name, 25, 5){
};
PresidentialPardonForm::PresidentialPardonForm() : AForm("sol", 25, 5) {

}
PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &temp) : AForm(temp) {
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &temp) {
    AForm::operator=(temp);
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executer) const
{
    isExecuteable(executer);
    std::cout << executer.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}