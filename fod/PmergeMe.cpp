#include "PmergeMe.hpp"
#include <iostream>

void PMergeMe::binaryinaryinsertion(std::pair<int, int> item, std::vector<std::pair<int, int> >&d)
{
    int start_idx = 0;
    int mid = 0;
    int last_idx = d.size();
    while (start_idx < last_idx) {
        this->num += 1;
        mid = (start_idx + last_idx) / 2;
        if (d[mid].first < item.first) {
            start_idx = mid + 1;
        } else {
            last_idx = mid;
        }
    }
    d.insert(d.begin() + start_idx, std::make_pair(item.first, item.second));
}


std::vector<std::pair<int, int> > PMergeMe::mergeInsertion(std::vector<std::pair<int, int> >&d) {
    std::vector<std::pair<int, int> > a;
    std::vector<std::pair<int, int> > b;
    std::vector<std::pair<int, int> > newB;
    std::vector<std::pair<int, int> > m;
    std::vector<int> newD;

    int n = d.size();

    if (n <= 1) {
        return d;
    }
    for (int i = 0; i < n/2 ; i++) {
        this->num+=1;
        if (d[i] > d[i + n / 2]) {
            a.push_back(std::make_pair(d[i].first, i));
            b.push_back(std::make_pair(d[i + n / 2].first, i + n / 2));
        } else {
            b.push_back(std::make_pair(d[i].first, i));
            a.push_back(std::make_pair(d[i + n / 2].first, i + n / 2));
        }
    }
    if (n % 2 == 1) {
        b.push_back(std::make_pair(d[n - 1].first, n - 1));
    }
    std::cout << "=====prev: a ==== " <<std::endl;
    for (int i = 0; i < (int)a.size(); i++) {
        std::cout << a[i].second << " ";
    }
    std::cout <<std::endl;
    a = mergeInsertion(a);
    std::cout << "=====test: a ==== " <<std::endl;
    for (int i = 0; i < (int)a.size(); i++) {
        std::cout <<"first : " << a[i].first << " second : " << a[i].second << " ";
    }
    std::cout <<std::endl;
    std::cout << "=====newIdx: a ==== " <<std::endl;
    for (int i = 0; i < n / 2; i++) {
        int newIdx = a[i].second;
        // if (newIdx >= n) {
        //     newIdx -= n;
        // }
        std::cout <<"newIdx : " << newIdx << " a[]: " << a[i].second << " ";
        newB.push_back(b.at(newIdx));
    }
    std::cout <<std::endl;
    if (n % 2 == 1) {
        newB.push_back(b.at(n / 2));
    }
        std::cout << "=====after: b ==== " <<std::endl;
    for (int i = 0; i < (int)newB.size(); i++) {
        std::cout << newB[i].first << " ";
    }
    std::cout <<std::endl;
   a.insert(a.begin(), newB.at(0));

    std::vector <int>t;
                               
    t.push_back(1);
    t.push_back(1);
    t.push_back(3);
    t.push_back(5);
    t.push_back(11);
    t.push_back(21);
    t.push_back(43);
    t.push_back(85);
    t.push_back(171);
    t.push_back(341);
    t.push_back(683);
    t.push_back(1365);
    t.push_back(2731);
    t.push_back(5461);
    t.push_back(10923);
    t.push_back(21845);
    t.push_back(43691);
    t.push_back(87381);
    t.push_back(174763);
    
    int k = 2;

    while (t[k - 1] < n / 2 + n % 2) {
        int t_m = std::min(t[k], n / 2 + n%2);
        for (int i = t_m; i >= t[k - 1] + 1; i--) {
            PMergeMe::binaryinaryinsertion(newB[i - 1], a);
        }
        k = k + 1;
    }
    std::cout << std::endl;
    return a;
};