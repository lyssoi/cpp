#ifndef ROBOTMYREQUESTFORM
#define ROBOTMYREQUESTFORM

#include "AForm.hpp"
#include <string>

class RobotmyRequestForm : public AForm
{
public:
    RobotmyRequestForm(const string &name);
    void execute(const Bureaucrat &executer);
};

#endif