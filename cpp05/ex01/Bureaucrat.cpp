#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("grade too low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("grade too high!");
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const std::string &name) : name(name)
{
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
        return (*this);
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

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " "  << e.what() << std::endl;
    }
} 