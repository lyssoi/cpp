#ifndef PMERGE_ME
#define PMERGE_ME
#include <vector>

class PMergeMe {
    private:
    public:
        std::vector<int> not_sorted;
        std::vector<int> sorted;
        std::vector<int> mergeInsertion(std::vector<int> d);
        std::vector<int> binaryinaryinsertion(std::pair<int, int> item, std::vector<int>d);
};

#endif