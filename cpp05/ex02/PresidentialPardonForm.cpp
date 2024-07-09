#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const string &name) : AForm(name, 25, 5){

                                                                     };

void PresidentialPardonForm::execute(const Bureaucrat &executer) const
{
    if (executer.getGrade() > this->getGradeForExecute())
    {
        throw PresidentialPardonForm::GradeTooLowException();
    }
    std::cout << executer.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}