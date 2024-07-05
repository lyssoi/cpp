#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
    std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &temp);
    Bureaucrat &operator=(const Bureaucrat &temp);
    std::string getName() const;
    int getGrade() const;
    void incrementGrade(int num);
    void decrementGrade(int num);
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("grade too high!");
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("grade too low!");
        }
    };
};

#endif