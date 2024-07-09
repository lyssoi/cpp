#include "ShruberryCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm(const std::string &name) : AForm(name, 145, 137)
{
}

void ShruberryCreationForm::execute(const Bureaucrat &executer)
{
    std::stringstream ss;
}
