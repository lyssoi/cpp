#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int grade_for_sign, int grade_for_execute) : name(name), is_signed(false), grade_for_sign(grade_for_sign), grade_for_execute(grade_for_execute)
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
AForm::AForm(const AForm &temp) : name(temp.getName()), is_signed(temp.getIsSigned()), grade_for_sign(temp.getGradeForSign()), grade_for_execute(temp.getGradeForExecute())
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