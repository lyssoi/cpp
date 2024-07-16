#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack(){};
        ~MutantStack(){};
        MutantStack(const MutantStack &temp){
            *this = temp;
        };
        MutantStack &operator=(const MutantStack &temp){
            if (this == &temp)
                return (*this);
            return *this;
        };

        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin() { return this->c.begin();};
        iterator end() { return this->c.end();};

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() { return this->c.rebegin();};
        reverse_iterator rend() { return this->c.rend();};
};

#endif