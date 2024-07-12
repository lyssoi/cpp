#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data {
    int number;
};

class Serializer {
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &temp);
        Serializer &operator=(const Serializer &tmep);
        uintptr_t serialize(Data *ptr);
        Data *deserialize(uintptr_t raw);
};
#endif