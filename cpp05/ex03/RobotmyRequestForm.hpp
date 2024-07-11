#ifndef ROBOTMYREQUESTFORM
#define ROBOTMYREQUESTFORM

#include "AForm.hpp"
#include <string>

class RobotmyRequestForm : public AForm
{
public:
    RobotmyRequestForm();
    ~RobotmyRequestForm();
    RobotmyRequestForm(const RobotmyRequestForm &temp);
    RobotmyRequestForm &operator=(const RobotmyRequestForm &temp);
    RobotmyRequestForm(const std::string &name);
    void execute(const Bureaucrat &executor) const;
};

#endif