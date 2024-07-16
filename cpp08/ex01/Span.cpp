#include "Span.hpp"

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
    if (this->integers.size() == len) {
        throw std::range_error("The span was full ");
    }
    std::vector <int> ::iterator it = find(this->integers.begin(), this->integers.end(), num);
    if (it != this->integers.end()){
        throw std::invalid_argument("The value is in the container already");
    }
    this->integers.push_back(num);
}

unsigned int Span::shortestSpan() {
    unsigned int shortest = 4294967295;
    if (this->integers.size() < 2) {
        return (0);
    };
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

unsigned int Span::longestSpan() {
    if (this->integers.size() < 2) {
        return (0);
    }
    int maxnum = *std::max_element(this->integers.begin(), this->integers.end());
    int minnum = *std::min_element(this->integers.begin(), this->integers.end());
    return (maxnum - minnum);
    // max값과 min값 찾아서 max - min 리턴
}

void Span::addManyNumber(const std::vector<int> &vec) {
    if (this->integers.size() + vec.size() > len) {
        throw std::range_error("The span was full ");
    }
    this->integers.insert(this->integers.end(), vec.begin(), vec.end());
}