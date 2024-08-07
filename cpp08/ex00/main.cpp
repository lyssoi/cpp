#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

int main() {
    {
        std::cout << "======= vector =======" << std::endl;
        try {
            std::vector<int> v;
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
            v.push_back(4);
            std::vector<int> ::iterator it =  easyfind(v, 1);
            std::cout << *it << std::endl; 
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << "======= deque =======" << std::endl;
        try {
            std::deque<int> d;
            d.push_back(1);
            d.push_back(2);
            d.push_back(3);
            d.push_back(4);
            std::deque<int> ::iterator it =  easyfind(d, 2);
            std::cout << *it << std::endl; 
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << "======= list =======" << std::endl;
        try {
            std::list<int> li;
            li.push_back(1);
            li.push_back(2);
            li.push_back(3);
            li.push_back(4);
            std::list<int> ::iterator it = easyfind(li, 5);
            std::cout << *it << std::endl; 
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}