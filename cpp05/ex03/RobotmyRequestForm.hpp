#ifndef ROBOTMYREQUESTFORM
#define ROBOTMYREQUESTFORM

#include "AForm.hpp"
#include <string>

class RobotmyRequestForm : public AForm
{
private:
    const std::string target;
    RobotmyRequestForm();
    RobotmyRequestForm(const RobotmyRequestForm &temp);
    RobotmyRequestForm &operator=(const RobotmyRequestForm &temp);
public:
    ~RobotmyRequestForm();
    RobotmyRequestForm(const std::string &target);
    const std::string &getTarget() const;
    void execute(const Bureaucrat &executor) const;
};

#endif