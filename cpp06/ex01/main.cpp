#include "Serializer.hpp"

int main() {
    Data data;
    Data *dataPtr;
    Serializer serial;

    data.number = 2;
    dataPtr = &data;

    std::cout << "data adress  :" << dataPtr << std::endl;

    uintptr_t ptr = serial.serialize(dataPtr);
    std::cout << "serialize    :" << ptr << std::endl;

    Data *deserailizeData = serial.deserialize(ptr);
    std::cout << "deserialize  :" << deserailizeData << std::endl;
}