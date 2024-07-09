#ifndef SHRUBERRYCREATIONFORM
#define SHRUBERRYCREATIONFORM

#include "AForm.hpp"

class ShruberryCreationForm : public AForm
{
    // sign 145, exec 147
public:
    ShruberryCreationForm(const std::string &name);
    void execute(const Bureaucrat &executer);
};

#endif