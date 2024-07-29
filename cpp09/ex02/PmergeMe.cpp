#include "PmergeMe.hpp"
#include <iostream>

std::vector<int> PMergeMe::binaryinaryinsertion(std::pair<int, int> item, std::vector<int>d)
{
    int start_idx = 0;
    int mid = 0;
    int last_idx = d.size();
    while (start_idx < last_idx) {
        mid = (start_idx + last_idx) / 2;
        if (d[mid] < num) {
            start_idx = mid + 1;
        } else {
            last_idx = mid;
        }
    }
    d.insert(d.begin() + start_idx, num);
    return d;
}


std::vector<int> PMergeMe::mergeInsertion(std::vector<int> d) {
    std::vector<int> a;
    std::vector<int> b;
    std::vector<std::pair<int, int> > m;
    std::vector<int> newD;

    int n = d.size();

    if (n <= 1) {
        return d;
    }
    for (int i = 0; i < n/2 ; i++) {
        a.push_back(std::max(d[i], d[i + n/2]));
        b.push_back(std::min(d[i], d[i + n/2])); 
    }
    if (n % 2 == 1) {
        b.push_back(d[n - 1]);
    }
    for (int i = 0; i < n/2; i++) {
        m.push_back(std::make_pair(a[i], b[i]));
    }
    a = mergeInsertion(a);
    // 이제 a는 바뀌어 있을 것임.
    // a의 짝을 찾아서, b의 위치를 바궈줘야함.
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            if (a[i] == m[j].first) {
                b[i] = m[j].second;
                break;
            }
        }
    }
    newD.push_back(b.at(0));
    newD.insert(newD.begin() + 1, a.begin(), a.end());
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
        int t_m = std::min(t[k], n/2 + n%2);
        for (int i = t_m; i >= t[k - 1] + 1; i--) {
            newD = PMergeMe::binaryinaryinsertion(b[i - 1], newD);
        }
        k = k + 1;
    }
    return newD;
};