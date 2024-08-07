#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    const int grade_for_sign;
    const int grade_for_execute;
    bool is_signed;

public:
    AForm();
    virtual ~AForm(){};
    AForm(const std::string &name, int grade_for_sign, int grade_for_execute);
    AForm(const AForm &temp);
    AForm &operator=(const AForm &temp);
    void beSigned(const Bureaucrat &bureaucrat);
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeForSign() const;
    int getGradeForExecute() const;
    virtual void execute(Bureaucrat const &executor) const = 0;
    void isExecuteable(Bureaucrat const &executor) const;
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
    class NotSignException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

#endif