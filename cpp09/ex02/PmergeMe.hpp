#ifndef PMERGE_ME
#define PMERGE_ME
#include <vector>
#include <list>
#include <sys/time.h>
#include <sstream>
#include <exception>
#include <algorithm> 
#include <iterator> 

enum {
    VECTOR,
    LIST
};

class PmergeMe {
    private:
    public:
        long long v_time;
        long long l_time;
        std::vector<std::pair<int, int> > v_not_sorted;
        std::vector<std::pair<int, int> > v_sorted;
        std::list<std::pair<int, int> > l_not_sorted;
        std::list<std::pair<int, int> > l_sorted;
        PmergeMe() {};
        ~PmergeMe() {};
        PmergeMe(const PmergeMe &tmp);
        PmergeMe &operator=(const PmergeMe &tmp);
        void print();
        void vectorRun(int argc, char *argv[]);
        void listRun(int argc, char *argv[]);
        void timeoutput(struct timeval start, struct timeval end, int type);
        std::vector<std::pair<int, int> > vectorInit(int argc, char *argv[]);
        std::list<std::pair<int, int> > listInit(int artc, char *argv[]);
        std::vector<std::pair<int, int> > mergeInsertion(std::vector<std::pair<int, int> > &d);
        void binaryinaryinsertion(std::pair<int, int> item, std::vector<std::pair<int, int> >&d);
        std::list<std::pair<int, int> > mergeInsertion(std::list<std::pair<int, int> > &d);
        void binaryinaryinsertion(std::pair<int, int> item, std::list<std::pair<int, int> >&d);
};

#endif