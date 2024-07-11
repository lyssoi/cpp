#include "RobotmyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <stdlib.h>
#include <time.h>

RobotmyRequestForm::RobotmyRequestForm() : AForm("sol", 25, 5) {

}
RobotmyRequestForm::~RobotmyRequestForm() {};

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &temp) : AForm(temp) {
}
RobotmyRequestForm &RobotmyRequestForm::operator=(const RobotmyRequestForm &temp) {
    AForm::operator=(temp);
    return (*this);
}

RobotmyRequestForm::RobotmyRequestForm(const std::string &name) : AForm(name, 72, 45){};

void RobotmyRequestForm::execute(const Bureaucrat &executer) const
{
    isExecuteable(executer);
    srand(time(NULL));
    int tmp = rand() % 2;
    if (tmp)
    {
        std::cout << executer.getName() << " has been robotomized" << std::endl;
    }
    else
    {
        std::cout << executer.getName() << " robotomy failed." << std::endl;
    }
};