#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

template <typename T>
typename T ::iterator easyfind(T container, int i) {
    typename T::iterator it = find(container.begin(), container.end(), i);
    if (it != container.end())
        return (it);
    throw std::out_of_range("The container doesn't contain this value");
}


#endif