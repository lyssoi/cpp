#ifndef SHRUBERRYCREATIONFORM
#define SHRUBERRYCREATIONFORM

#include "AForm.hpp"

class ShruberryCreationForm : public AForm
{
public:
    ShruberryCreationForm();
    ~ShruberryCreationForm();
    ShruberryCreationForm(const ShruberryCreationForm &temp);
    ShruberryCreationForm &operator=(const ShruberryCreationForm &temp);
    ShruberryCreationForm(const std::string &name);
    void execute(const Bureaucrat &executor) const;
    class fileOpenErrorException : public std::exception {
        public :
            const char *what() const throw();
    };
};

#endif