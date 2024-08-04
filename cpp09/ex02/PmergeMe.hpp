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
        long long v_time;
        long long l_time;
        std::vector<std::pair<int, int> > v_not_sorted;
        std::vector<std::pair<int, int> > v_sorted;
        std::list<std::pair<int, int> > l_not_sorted;
        std::list<std::pair<int, int> > l_sorted;
    public:
        void print();
        void vectorRun(int argc, char *argv[]); // vector 시간 초기화해서 출력하고, vector_init하고, 소팅하고, 시간출력하기
        void listRun(int argc, char *argv[]); //list 시간 초기화해서 출력하고, vector_init하고, 소팅하고, 시간출력하기
        void timeoutput(struct timeval start, struct timeval end, int type);
        std::vector<std::pair<int, int> > vectorInit(int argc, char *argv[]);
        std::list<std::pair<int, int> > listInit(int artc, char *argv[]);
        void print_sorted();
        void print_notsorted();
        void print_time();
        std::vector<std::pair<int, int> > mergeInsertion(std::vector<std::pair<int, int> > &d);
        void binaryinaryinsertion(std::pair<int, int> item, std::vector<std::pair<int, int> >&d);
        std::list<std::pair<int, int> > mergeInsertion(std::list<std::pair<int, int> > &d);
        void binaryinaryinsertion(std::pair<int, int> item, std::list<std::pair<int, int> >&d);
};

#endif