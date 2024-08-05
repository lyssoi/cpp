#include "Span.hpp"
#include <iostream>

int main()
{
    try {
        Span sp = Span(15);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.print();

        std::vector<int> vec;
        vec.push_back(3);
        vec.push_back(5);
        vec.push_back(7);
        vec.push_back(9);
        sp.addManyNumber(vec);
        sp.print();
        sp.addManyNumber(vec.begin() + 1, vec.end());
        sp.print();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}