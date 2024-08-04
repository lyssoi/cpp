#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) 
{
    PmergeMe p;

    p.vectorRun(argc, argv);
    p.listRun(argc, argv);
    p.print();
    // PMergeMe p;

    // p.num = 0;
    // for (int i = 1; i < argc; i++) {
    //     // atoi 말고 ssstream으로 변경할것. positive int형 아니면 그냥 예외처리 해버리기
    //     p.not_sorted.push_back(std::make_pair(atoi(argv[i]), i - 1));
    // }
    // p.sorted = p.mergeInsertion(p.not_sorted);
    // for (size_t i = 0; i < p.sorted.size(); i++) {
    //     std::cout << p.sorted[i].first << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "비교 : " << p.num << std::endl;
}