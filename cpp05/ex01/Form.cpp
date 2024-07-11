#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooLowException::what() const throw() {
    return ("grade too low!");
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("grade too high!");
}

Form::Form() : name("sol"),is_signed(false),grade_for_sign(100), grade_for_execute(20) {};

Form::Form(const std::string &name, int grade_for_sign, int grade_for_execute) : name(name), is_signed(false), grade_for_sign(grade_for_sign), grade_for_execute(grade_for_execute) {
    if (grade_for_sign < 1 || grade_for_execute < 1 ) {
        throw Form::GradeTooHighException();
    }
    if (grade_for_execute > 150 || grade_for_execute > 150) {
        throw Form::GradeTooLowException();
    }
};
Form::Form (const Form &temp) : name(temp.getName()), is_signed(temp.getIsSigned()), grade_for_sign(temp.getGradeForSign()), grade_for_execute(temp.getGradeForExecute()) {
    if (grade_for_sign < 1 || grade_for_execute < 1 ) {
        throw Form::GradeTooHighException();
    }
    if (grade_for_execute > 150 || grade_for_execute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form &Form::operator=(const Form &temp) {
    if (this == &temp)
        return (*this);
    is_signed =temp.getIsSigned();
    return (*this);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (grade_for_sign >= bureaucrat.getGrade()) {
        is_signed = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

const std::string &Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return is_signed;
}

int Form::getGradeForSign() const {
    return grade_for_sign;
}

int Form::getGradeForExecute() const {
    return grade_for_execute;
}