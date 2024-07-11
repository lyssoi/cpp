#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotmyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "Intern.hpp"

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
        Intern someIntern;
        AForm *form0;
        AForm *form1;
        AForm *form2;
        AForm *form3;

        std::cout << kim << std::endl;
        kim.incrementGrade(145);
        std::cout << kim << std::endl;

        form1 = someIntern.makeForm("ShruberryCreationForm", "form1");
        kim.signForm(*form1);
        kim.executeForm(*form1);
        delete form1;
    
        form2 = someIntern.makeForm("RobotmyRequestForm", "form2");
        kim.signForm(*form2);
        kim.executeForm(*form2);
        delete form2;
        
        form3 = someIntern.makeForm("PresidentialPardonForm", "form3");
        kim.signForm(*form3);
        kim.executeForm(*form3);
        delete form3;
    
        form0 = someIntern.makeForm("", "form0");
        kim.executeForm(*form0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
};