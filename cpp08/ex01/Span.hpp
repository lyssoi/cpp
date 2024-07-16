#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

//vector를 써서 저장하고 
class Span {
    private:
        std::vector <int>integers;
        unsigned int len;
    public:
        Span(){};
        ~Span(){};
        Span(unsigned int N);
        Span(const Span &temp);
        Span &operator=(const Span &temp);
        void addNumber(int num);
        void addManyNumber(const std::vector<int> &vec);
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif