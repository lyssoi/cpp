#include "PmergeMe.hpp"
#include <iostream>

void PmergeMe::print() {
    // std::cout << "===Vector=== " << std::endl;
    std::cout << "Before ";
    for (int i = 0; i < (int) v_not_sorted.size(); i++){
        std::cout << " " << v_not_sorted[i].first;
    }
    std::cout << std::endl;
    std::cout << "After ";
    for (int i = 0; i < (int) v_sorted.size(); i++){
        std::cout << " " << v_sorted[i].first;
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of 3000 elements with std::" << "vector" << " : " << v_time << " us" <<std::endl;
    // std::cout << "===List=== " << std::endl;
    // std::cout << "Before ";
    // for (std::list<std::pair<int, int> >::iterator it = l_not_sorted.begin(); it != l_not_sorted.end(); ++it) {
    //     std::cout << " " << it->first;
    // }
    // std::cout << std::endl;
    
    // std::cout << "After ";
    // for (std::list<std::pair<int, int> >::iterator it = l_sorted.begin(); it != l_sorted.end(); ++it) {
    //     std::cout << " " << it->first;
    // }
    // std::cout << std::endl;
    std::cout << "Time to process a range of 3000 elements with std::" << "list" << " : " << l_time << " us" <<std::endl;
}

void PmergeMe::vectorRun(int argc, char *argv[]) {
    struct timeval start, end;

    gettimeofday(&start, NULL);

    v_not_sorted = vectorInit(argc,argv);
    v_sorted = mergeInsertion(v_not_sorted);

    gettimeofday(&end, NULL);
    timeoutput(start, end, VECTOR);
}

std::vector<std::pair<int, int> > PmergeMe::vectorInit(int argc, char *argv[]) {
    std::vector <std::pair<int, int> > not_sorted;

    for (int i = 1; i < argc; i++) {
        std::stringstream ss(argv[i]);
        int num;
        if (!(ss >> num)) {
            throw std::runtime_error("Invalid number : " + ss.str());
        }
        if (num <= 0) {
            throw std::runtime_error("Not positive integer : " + ss.str());
        }
        not_sorted.push_back(std::make_pair(num, i - 1));
    }
    return not_sorted;
}


void PmergeMe::listRun(int argc, char *argv[]) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    l_not_sorted = listInit(argc, argv);
    l_sorted = mergeInsertion(l_not_sorted);
    gettimeofday(&end, NULL);
    timeoutput(start, end, LIST);
}

std::list<std::pair<int, int> > PmergeMe::listInit(int argc, char *argv[]) {
    std::list<std::pair<int, int> > not_sorted;

    for (int i = 1; i < argc; i++) {
        std::stringstream ss(argv[i]);
        int num;
        if (!(ss >> num)) {
            throw std::runtime_error("Invalid number : " + ss.str());
        }
        if (num <= 0) {
            throw std::runtime_error("Not positive integer : " + ss.str());
        }
        not_sorted.push_back(std::make_pair(num, i - 1));
    }
    return not_sorted;
}


std::list<std::pair<int, int> > PmergeMe::mergeInsertion(std::list<std::pair<int, int> >& d) {
    std::list<std::pair<int, int> > a;
    std::list<std::pair<int, int> > newA;
    std::list<std::pair<int, int> > oldA;
    std::list<std::pair<int, int> > newB;
    std::list<std::pair<int, int> > oldB;
    int n = d.size();

    if (n <= 1) {
        return d;
    }

    std::list<std::pair<int, int> >::iterator it = d.begin();
    for (int i = 0; i < n / 2; i++, ++it) {
        std::list<std::pair<int, int> >::iterator next_it = std::next(it, n / 2);
        if (*it > *next_it) {
            a.push_back(std::make_pair(it->first, i));
            oldA.push_back(*it);
            oldB.push_back(*next_it);
        } else {
            a.push_back(std::make_pair(next_it->first, i));
            oldB.push_back(*it);
            oldA.push_back(*next_it);
        }
    }
    if (n % 2 == 1) {
        it = std::next(d.begin(), n - 1);
        oldB.push_back(*it);
    }
    newA = mergeInsertion(a);
    for (std::list<std::pair<int, int> >::iterator newA_it = newA.begin(); newA_it != newA.end(); ++newA_it) {
        int newIdx = newA_it->second;
        std::list<std::pair<int, int> >::iterator oldB_element_it = std::next(oldB.begin(), newIdx);
        newB.push_back(*oldB_element_it);
    }
    if (n % 2 == 1) {
        newB.push_back(*std::next(oldB.begin(), n / 2));
    }
    std::list<std::pair<int, int> >::iterator oldA_it = oldA.begin();
    for (std::list<std::pair<int, int> >::iterator newA_it = newA.begin(); newA_it != newA.end(); ++newA_it) {
        std::advance(oldA_it, newA_it->second);
        newA_it->second = oldA_it->second;
        oldA_it = oldA.begin();
    } 
    newA.insert(newA.begin(), newB.front());

    int tk = 1;
    int two = 2;
    while (tk < n / 2 + n % 2) {
        int t_m = std::min(two * 2 - tk, n / 2 + n % 2);
        for (int i = t_m; i >= tk + 1; i--) {
            binaryinaryinsertion(*std::next(newB.begin(), i - 1), newA);
        }
        two *= 2;
        tk = two - tk;
    }
    return newA;
}

void PmergeMe::binaryinaryinsertion(std::pair<int, int> item, std::list<std::pair<int, int> >& d) {
    std::list<std::pair<int, int> >::iterator start_it = d.begin();
    std::list<std::pair<int, int> >::iterator end_it = d.end();
    std::list<std::pair<int, int> >::iterator mid_it;

    while (start_it != end_it) {
        int distance = std::distance(start_it, end_it) / 2;
        mid_it = std::next(start_it, distance);
        if (mid_it->first < item.first) {
            start_it = ++mid_it;
        } else {
            end_it = mid_it;
        }
    }
    d.insert(start_it, item);
}


void PmergeMe::timeoutput(struct timeval start, struct timeval end, int type) {
    long s = end.tv_sec - start.tv_sec;
    long ms = end.tv_usec - start.tv_usec;
    long long us = s * 1000000 + ms;

    if (type == VECTOR) {
        v_time = us;
    } else if (type == LIST) {
        l_time = us;
    } else {
        throw std::runtime_error("Wrong type");
    }
    //std::cout << "Time to process a range of 3000 elements with std::" << container << " : " << us << " us" <<std::endl;
}

void PmergeMe::binaryinaryinsertion(std::pair<int, int> item, std::vector<std::pair<int, int> >&d)
{
    int start_idx = 0;
    int mid = 0;
    int last_idx = d.size();
    while (start_idx < last_idx) {
        mid = (start_idx + last_idx) / 2;
        if (d[mid].first < item.first) {
            start_idx = mid + 1;
        } else {
            last_idx = mid;
        }
    }
    d.insert(d.begin() + start_idx, item);
}


std::vector<std::pair<int, int> > PmergeMe::mergeInsertion(std::vector<std::pair<int, int> >&d) {
    std::vector<std::pair<int, int> > a;
    std::vector<std::pair<int, int> > newA;
    std::vector<std::pair<int, int> > oldA;
    std::vector<std::pair<int, int> > newB;
    std::vector<std::pair<int, int> > oldB;
    int n = d.size();

    if (n <= 1) {
        return d;
    }
    for (int i = 0; i < n/2 ; i++) {
        if (d[i] > d[i + n / 2]) {
            a.push_back(std::make_pair(d[i].first, i));
            oldA.push_back(d[i]);
            oldB.push_back(d[i + n / 2]);
        } else {
            a.push_back(std::make_pair(d[i + n / 2].first, i));
            oldB.push_back(d[i]);
            oldA.push_back(d[i + n / 2]);
        }
    }
    if (n % 2 == 1) {
        oldB.push_back(d[n - 1]);
    }
    newA = mergeInsertion(a);
    for (int i = 0; i < n / 2; i++) {
        int newIdx = newA[i].second;
        newB.push_back(oldB.at(newIdx));
    }
    if (n % 2 == 1) {
        newB.push_back(oldB.at(n / 2));
    }
    for (int i = 0; i < n / 2; i++) {
        newA[i].second = oldA[newA[i].second].second;
    }
    newA.insert(newA.begin(), newB.at(0));

    int tk = 1;
    int two = 2;
    while (tk < n / 2 + n % 2) {
        int t_m = std::min(two * 2 - tk, n / 2 + n % 2);
        for (int i = t_m; i >= tk + 1; i--) {
            binaryinaryinsertion(newB[i - 1], newA);
        }
        two *= 2;
        tk = two - tk;
    }
    return newA;
};