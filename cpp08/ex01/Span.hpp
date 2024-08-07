#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>

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
        void addManyNumber(std::vector <int>::iterator first, std::vector <int>::iterator last);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        void print();
};

#endif