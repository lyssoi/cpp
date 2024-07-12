#ifndef ITER_HPP
#define ITER_HPP

#include <stdint.h>
#include <stddef.h>

// template <typename T>
// void iter( T* addr, size_t len, void (*func)(T &)){
//     if(func == nullptr) {
//         return ;
//     }
//     for (size_t i = 0; i < len; i++) {
//         func(addr[i]);
//     }

// }

// template <typename T>
// void iter(const T* addr, size_t len, void (*func)(const T &)){
//     if(func == nullptr) {
//         return ;
//     }
//     for (size_t i = 0; i < len; i++) {
//         func(addr[i]);
//     }
// }

template <typename T, typename F>
void iter(T* addr, size_t len, F func){
    if(func == nullptr) {
        return ;
    }
    for (size_t i = 0; i < len; i++) {
        func(addr[i]);
    }
}

#endif