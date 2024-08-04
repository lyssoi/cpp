#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
    private:
        Intern(const Intern &temp);
        Intern &operator=(const Intern &temp);
    public:
        Intern(){};
        ~Intern(){};
        AForm *makeForm(const std::string &formName, const std::string &targetName);
        AForm *makeShruberryCreationForm(const std::string &targetName);
        AForm *makeRobotmyRequestForm(const std::string &targetName);
        AForm *makePresidentialPardonForm(const std::string &targetName);
        class FormException : public std::exception {
            public :
                const char *what() const throw();
        };    
};

# endif