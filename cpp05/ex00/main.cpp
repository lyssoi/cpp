#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &temp)
{
    os << temp.getName() << ", bureaucrat grade " << temp.getGrade();
    return os;
}

int main()
{

    Bureaucrat kim = Bureaucrat("kim");
    Bureaucrat park = Bureaucrat("park");
    try
    {
        std::cout << kim << std::endl;
        std::cout << park << std::endl;
        kim.incrementGrade(100);
        kim.decrementGrade(10);
        park.incrementGrade(150);
        std::cout << kim << std::endl;
        std::cout << park << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
};