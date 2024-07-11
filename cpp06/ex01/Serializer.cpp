#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

        // uintptr_t serialize(Data *ptr);
        // //It takes a pointer and converts it to the unsigned integer type uintptr_t.
        // Data *deserialize(uintptr_t raw);