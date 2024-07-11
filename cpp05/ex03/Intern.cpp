#include "Intern.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotmyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(const Intern &temp) {
    *this = temp;
}

Intern &Intern::operator=(const Intern &temp) {
    (void)temp;
    return *this;
}

AForm *Intern::makeShruberryCreationForm(const std::string &targetName)
{
    return new ShruberryCreationForm(targetName);
}

AForm *Intern::makeRobotmyRequestForm(const std::string &targetName)
{
    return new RobotmyRequestForm(targetName);
}

AForm *Intern::makePresidentialPardonForm(const std::string &targetName)
{
    return new PresidentialPardonForm(targetName);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &targetName)
{
    std::string formNames[3] = {"ShruberryCreationForm","RobotmyRequestForm","PresidentialPardonForm"};
    AForm *(Intern::*func[3])(const std::string &targetName) = {&Intern::makeShruberryCreationForm, &Intern::makeRobotmyRequestForm, &Intern::makePresidentialPardonForm};

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i])
            return (this->*(func[i]))(targetName);
    }
    throw FormException();
}

const char *Intern::FormException:: what() const throw() {
    return ("form does not exist");
}