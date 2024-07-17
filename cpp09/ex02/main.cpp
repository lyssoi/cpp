#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) 
{
    PMergeMe p;
    for (int i = 1; i < argc; i++) {
        p.not_sorted.push_back(atoi(argv[i]));
    }
    p.sorted = p.mergeInsertion(p.not_sorted);
    for (size_t i = 0; i < p.sorted.size(); i++) {
        std::cout << p.sorted[i] << " ";
    }
    std::cout << std::endl;
}