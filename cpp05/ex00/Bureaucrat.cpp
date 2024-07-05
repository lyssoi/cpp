#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name)
{
    this->name = name;
    grade = 150;
}

Bureaucrat::~Bureaucrat(){};
Bureaucrat::Bureaucrat(const Bureaucrat &temp)
{
    *this = temp;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &temp)
{
    if (this == &temp)
        return;
    this->name = temp.getName();
    this->grade = temp.getGrade();
    return (*this);
}

void Bureaucrat::decrementGrade(int num)
{
    this->grade += num;
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::incrementGrade(int num)
{
    this->grade -= num;
    if (this->grade < 0)
        throw Bureaucrat::GradeTooHighException();
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}
