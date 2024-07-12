#include "Iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(T &a) {
    std::cout << a << std::endl;
}


int main() {
    int intarr[5] = {0,1,2,3,4};
    const std::string strarr[5] = {"a","b","c","d","e"};

    iter(intarr, 5, print<int>);
    iter(strarr, 5, print<const std::string>);
    return 0;
}