#include "RobotmyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <stdlib.h>
#include <time.h>

RobotmyRequestForm::RobotmyRequestForm() : AForm("RobotmyRequestForm", 72, 45) {

}
RobotmyRequestForm::~RobotmyRequestForm() {};

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &temp) : AForm(temp) {
}
RobotmyRequestForm &RobotmyRequestForm::operator=(const RobotmyRequestForm &temp) {
    AForm::operator=(temp);
    return (*this);
}


RobotmyRequestForm::RobotmyRequestForm(const std::string &target) : AForm("RobotmyRequestForm", 72, 45), target(target){

};

const std::string &RobotmyRequestForm::getTarget() const {
    return this->target;
}

void RobotmyRequestForm::execute(const Bureaucrat &executer) const
{
    isExecuteable(executer);
    srand(time(NULL));
    int tmp = rand() % 2;
    std::cout << ".......drilling........" <<std::endl;
    if (tmp)
    {
        std::cout << getTarget() << " has been robotomized" << std::endl;
    }
    else
    {
        std::cout << getTarget() << " robotomy failed." << std::endl;
    }
};