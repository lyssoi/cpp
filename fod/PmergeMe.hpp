#ifndef PMERGE_ME
#define PMERGE_ME
#include <vector>

class PMergeMe {
    public:
        int num;
        std::vector<std::pair<int, int> > not_sorted;
        std::vector<std::pair<int, int> > sorted;
        std::vector<std::pair<int, int> > mergeInsertion(std::vector<std::pair<int, int> > &d);
        void binaryinaryinsertion(std::pair<int, int> item, std::vector<std::pair<int, int> >&d);
};

#endif