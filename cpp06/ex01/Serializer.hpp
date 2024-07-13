#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data {
    int number;
};

class Serializer {
    private:
        Serializer(const Serializer &temp);
        Serializer &operator=(const Serializer &tmep);
    public:
        Serializer();
        ~Serializer();
        uintptr_t serialize(Data *ptr);
        Data *deserialize(uintptr_t raw);
};
#endif