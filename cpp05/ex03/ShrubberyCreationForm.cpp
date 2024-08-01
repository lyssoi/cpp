#include "ShruberryCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm() : AForm("ShruberryCreationForm", 145, 137) {
}
ShruberryCreationForm::~ShruberryCreationForm() {};

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &temp) : AForm(temp) {
}
ShruberryCreationForm &ShruberryCreationForm::operator=(const ShruberryCreationForm &temp) {
    AForm::operator=(temp);
    return (*this);
}
const char *ShruberryCreationForm::fileOpenErrorException:: what() const throw() {
    return ("file not open!");
}

ShruberryCreationForm::ShruberryCreationForm(const std::string &target) : AForm("ShruberryCreationForm", 145, 137), target(target)
{
}

const std::string &ShruberryCreationForm::getTarget() const {
    return (this->target);
}

void ShruberryCreationForm::execute(const Bureaucrat &executor) const
{
    isExecuteable(executor);
    std::stringstream ss;

    ss << this->getName() << "_shrubbery";

    std::ofstream outFile(ss.str());

    if (!outFile) {
        fileOpenErrorException();
    }
    outFile << ".\n";
    outFile << "├── ex00\n";
    outFile << "│ ├── Bureaucrat.cpp\n";
    outFile << "│ ├── Bureaucrat.hpp\n";
    outFile << "│ ├── Makefile\n";
    outFile << "│ └── main.cpp\n";
    outFile << "├── ex01\n";
    outFile << "│ ├── AForm.cpp\n";
    outFile << "│ ├── AForm.hpp\n";
    outFile << "│ ├── Bureaucrat.cpp\n";
    outFile << "│ ├── Bureaucrat.hpp\n";
    outFile << "│ ├── Form.cpp\n";
    outFile << "│ ├── Form.hpp\n";
    outFile << "│ ├── Makefile\n";
    outFile << "│ └── main.cpp\n";
    outFile << "└── ex02\n";
    outFile << "  ├── AForm.cpp\n";
    outFile << "  ├── AForm.hpp\n";
    outFile << "  ├── Bureaucrat.cpp\n";
    outFile << "  ├── Bureaucrat.hpp\n";
    outFile << "  ├── Makefile\n";
    outFile << "  ├── PresidentialPardonForm.cpp\n";
    outFile << "  ├── PresidentialPardonForm.hpp\n";
    outFile << "  ├── RobotmyRequestForm.cpp\n";
    outFile << "  ├── RobotmyRequestForm.hpp\n";
    outFile << "  ├── ShrubberyCreationForm.cpp\n";
    outFile << "  ├── ShruberryCreationForm.hpp\n";
    outFile << "  └── main.cpp\n";
    outFile.close();
    std::cout << getTarget() << " create file" << std::endl;
}
