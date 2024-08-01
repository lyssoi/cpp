#ifndef SHRUBERRYCREATIONFORM
#define SHRUBERRYCREATIONFORM

#include "AForm.hpp"

class ShruberryCreationForm : public AForm
{
private:
    const std::string target;
    ShruberryCreationForm();
    ShruberryCreationForm(const ShruberryCreationForm &temp);
    ShruberryCreationForm &operator=(const ShruberryCreationForm &temp);
public:
    ~ShruberryCreationForm();    
    ShruberryCreationForm(const std::string &target);
    void execute(const Bureaucrat &executor) const;
    const std::string &getTarget() const;
    class fileOpenErrorException : public std::exception {
        public :
            const char *what() const throw();
    };
};

#endif