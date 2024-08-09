#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        std::cerr << "invailid arguments" << std::endl;
        return 0;
    }
    try {
        PmergeMe p;

        p.vectorRun(argc, argv);
        //p.listRun(argc, argv);
        p.print();
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}