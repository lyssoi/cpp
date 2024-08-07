#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int N) {
    len = N;
}

Span::Span(const Span &temp) {
    *this = temp;
}

Span &Span::operator=(const Span &temp) {
    if (this == &temp)
        return (*this);
    this->integers.clear();
    std::vector <int> tempintegers = temp.integers;
    for (std::vector <int>::iterator it = tempintegers.begin(); it != tempintegers.end(); it++) {
        this->integers.push_back(*it);
    }
    return (*this);
}

void Span::addNumber(int num) {
    if (this->integers.size() >= len) {
        throw std::range_error("The span was full ");
    }
    this->integers.push_back(num);
}

unsigned int Span::shortestSpan() const {
    if (this->integers.size() < 2) {
        throw std::runtime_error("The span less han two");
    };
    unsigned int shortest = 4294967295;
    Span tmp = *this;
    sort(tmp.integers.begin(), tmp.integers.end());
    std::vector <int>::iterator prev = tmp.integers.begin();
    std::vector <int>::iterator curr = tmp.integers.begin() + 1;

    while (curr != tmp.integers.end()) {
        shortest = std::min(static_cast<unsigned int>(*curr - *prev), shortest);
        curr++;
        prev++;
    }
    return (shortest);
}

unsigned int Span::longestSpan() const {
    if (this->integers.size() < 2) {
        throw std::runtime_error("The span less han two");
    }
    int maxnum = *std::max_element(this->integers.begin(), this->integers.end());
    int minnum = *std::min_element(this->integers.begin(), this->integers.end());
    return (maxnum - minnum);
}

void Span::addManyNumber( std::vector <int>::iterator first, std::vector <int>::iterator last) {
    if (this->integers.size() + last - first > len) {
        throw std::range_error("The span was full ");
    }
    this->integers.insert(this->integers.end(), first, last);
}

void Span::addManyNumber(const std::vector<int> &vec) {
    if (this->integers.size() + vec.size() > len) {
        throw std::range_error("The span was full ");
    }
    this->integers.insert(this->integers.end(), vec.begin(), vec.end());
}

void Span::print() {
    std::cout << "====span ===" << std::endl;
    for (unsigned int i = 0; i < this->integers.size() ; i++){
        std::cout << this->integers.at(i) << " ";
    }
    std::cout << std::endl;
}