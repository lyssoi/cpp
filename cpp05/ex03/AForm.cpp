#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooLowException::what() const throw() {
    return ("grade too low!");
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("grade too high!");
}

const char *AForm::NotSignException::what() const throw() {
    return ("is not signed!");
}

AForm::AForm() : name("sol"), grade_for_sign(100), grade_for_execute(100), is_signed(false) {

};

AForm::AForm(const std::string &name, int grade_for_sign, int grade_for_execute) : name(name), grade_for_sign(grade_for_sign), grade_for_execute(grade_for_execute), is_signed(false)
{
    if (grade_for_sign < 1 || grade_for_execute < 1)
    {
        throw AForm::GradeTooHighException();
    }
    if (grade_for_execute > 150 || grade_for_execute > 150)
    {
        throw AForm::GradeTooLowException();
    }
};
AForm::AForm(const AForm &temp) : name(temp.getName()), grade_for_sign(temp.getGradeForSign()), grade_for_execute(temp.getGradeForExecute()), is_signed(temp.getIsSigned())
{
    if (grade_for_sign < 1 || grade_for_execute < 1)
    {
        throw AForm::GradeTooHighException();
    }
    if (grade_for_execute > 150 || grade_for_execute > 150)
    {
        throw AForm::GradeTooLowException();
    }
}

AForm &AForm::operator=(const AForm &temp)
{
    if (this == &temp)
        return (*this);
    is_signed = temp.getIsSigned();
    return (*this);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (grade_for_sign >= bureaucrat.getGrade())
    {
        is_signed = true;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
}

void AForm::isExecuteable(const Bureaucrat &executer) const {
    if (!this->getIsSigned())
    {
        throw AForm::NotSignException();
    }
    if (executer.getGrade() > this->getGradeForExecute())
    {
        throw AForm::GradeTooLowException();
    }
}

const std::string &AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return is_signed;
}

int AForm::getGradeForSign() const
{
    return grade_for_sign;
}

int AForm::getGradeForExecute() const
{
    return grade_for_execute;
}