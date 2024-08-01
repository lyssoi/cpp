#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotmyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &temp)
{
    os << temp.getName() << ", bureaucrat grade " << temp.getGrade();
    return os;
}

std::ostream &operator<<(std::ostream &os, const AForm &temp)
{
    std::string issigned;

    if (temp.getIsSigned()) {
        issigned = "is signed";
    } else
        issigned = "is not signed";
    os << temp.getName() << ", AForm " << issigned << ", grade for sign is " << temp.getGradeForSign() << " and grade for execute is " << temp.getGradeForExecute();
    return os;
}

int main()
{
    try
    {

        Bureaucrat kim = Bureaucrat("kim");
        PresidentialPardonForm pForm("trumph");
        RobotmyRequestForm rForm("robot");
        ShruberryCreationForm sForm("home");
        std::cout << kim << std::endl;
        kim.incrementGrade(145);
        std::cout << kim << std::endl;

        kim.signForm(pForm);
        kim.signForm(rForm);
        kim.signForm(sForm);
        kim.executeForm(pForm);
        kim.executeForm(rForm);
        kim.executeForm(sForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
};