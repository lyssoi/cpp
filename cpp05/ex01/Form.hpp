#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool is_signed;
    const int grade_for_sign;
    const int grade_for_execute;

public:
    Form();
    ~Form(){};
    Form(const std::string &name, int grade_for_sign, int grade_for_execute);
    Form(const Form &temp);
    Form &operator=(const Form &temp);
    void beSigned(const Bureaucrat &bureaucrat);
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeForSign() const;
    int getGradeForExecute() const;
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
        
    };
};

#endif