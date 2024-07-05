#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &temp)
{
    os << temp.getName() << ", bureaucrat grade " << temp.getGrade();
    return os;
}

std::ostream &operator<<(std::ostream &os, const Form &temp)
{
    std::string issigned;

    if (temp.getIsSigned()) {
        issigned = "is signed";
    } else
        issigned = "is not signed";
    os << temp.getName() << ", Form " << issigned << ", grade for sign is " << temp.getGradeForSign() << " and grade for execute is " << temp.getGradeForExecute();
    return os;
}

int main()
{

    Bureaucrat kim = Bureaucrat("kim");
    Bureaucrat park = Bureaucrat("park");
    Form form1 = Form("form1", 50, 50);

    try
    {
        std::cout << kim << std::endl;
        std::cout << park << std::endl;
        std::cout << form1 << std::endl;
        kim.incrementGrade(100);
        kim.signForm(form1);
        park.signForm(form1);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
};