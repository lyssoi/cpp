#include "RobotmyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotmyRequestForm::RobotmyRequestForm(const string &name) : AForm(name, 72, 45){};

void RobotmyRequestForm::execute(const Bureaucrat &executer)
{
    if (executer.getGrade() > this->getGradeForExecute())
    {
        throw RobotmyRequestForm::GradeTooLowException();
    }
    int tmp = rand() % 2;
    if (tmp)
    {
        std::cout << executer.getName() << " has been robotomized" << std::endl;
    }
    else
    {
        std::cout << executer.getGrade() << " robotomy failed." << std::endl;
    }
};