#ifndef Array_HPP
#define Array_HPP

#include <exception>

template <typename T>

class  Array {
    private:
        T *arr;
        int length;
    public:
        Array() : arr(new T[0]), length(0) {
        };
        Array(int n) : arr(new T[n]), length(n) {};
        ~Array() { delete []arr; }
        Array(const Array<T> &temp) :arr(new T[0]), length(0) { *this = temp; }
        Array &operator=(const Array<T> &temp) {
            if (this == &temp) {
                return (*this);
            }
            if (arr != NULL) {
                delete []arr;
                this->length = 0;
            }
            length = temp.size();
            arr = new T[temp.size()];
            for (int i = 0; i < temp.size(); i++) {
                arr[i] = temp[i];
            }
            return (*this);
        };
        T &operator[](int i) {
            if (i < 0 || i >= size() ) {
                throw Array<T>::arrayIdxException();
            }
            return arr[i];
        }
        const T&operator[](int i) const {
            if (i < 0 || i >= size() ) {
                throw Array<T>::arrayIdxException();
            }
            return arr[i];
        }
        int size() const { return this->length; } ;
        class arrayIdxException : public std::exception {
            public:
                const char *what() const throw() {
                    return ("Wrong idx! ");
                }
        };
};
#endif
