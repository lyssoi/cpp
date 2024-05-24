#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "print address" << std::endl;
    std::cout << "str memory address : " << &string << std::endl;
    std::cout << "stringPTR memory address : " << &string << std::endl;
    std::cout << "stringREF memory address : " << &string << std::endl;
    std::cout << std::endl;

    std::cout << "print value" << std::endl;
    std::cout << "str memory value : " << string << std::endl;
    std::cout << "stringPTR memory value : " << string << std::endl;
    std::cout << "stringREF memory value : " << string << std::endl;
}