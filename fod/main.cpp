#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) 
{
    PMergeMe p;
    std::vector<std::pair<int, int> > idxv;

    p.num = 0;
    for (int i = 1; i < argc; i++) {
        p.not_sorted.push_back(std::make_pair(atoi(argv[i]), i - 1));
    }
    p.sorted = p.mergeInsertion(p.not_sorted);
    for (size_t i = 0; i < p.sorted.size(); i++) {
        std::cout << p.sorted[i].first << " ";
    }
    std::cout << std::endl;

    std::cout << "비교 : " << p.num << std::endl;
}