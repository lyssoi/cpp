#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "print address" << std::endl;
    std::cout << "str memory address : " << &string << std::endl;
    std::cout << "stringPTR memory address : " << &stringPTR << std::endl;
    std::cout << "stringREF memory address : " << &stringREF << std::endl;
    std::cout << std::endl;

    std::cout << "print value" << std::endl;
    std::cout << "str memory value : " << string << std::endl;
    std::cout << "stringPTR memory value : " << stringPTR << std::endl;
    std::cout << "stringREF memory value : " << stringREF << std::endl;
}