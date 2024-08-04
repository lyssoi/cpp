#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) 
{
    try {
        PmergeMe p;

        p.vectorRun(argc, argv);
        p.listRun(argc, argv);
        p.print();
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
}