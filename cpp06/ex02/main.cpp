#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "time.h"
#include <iostream>

Base *generate(void) {
    srand(time(NULL));
    int tmp = rand() % 3;
    if (tmp == 0) {
        return new A();
    }
    else if (tmp == 1) {
        return new B();
    } else {
        return new C();
    }
}


void identify(Base *p) {
    if (dynamic_cast<A *>(p)){
        std::cout << "Pointer type A " << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "Pointer type B " << std::endl;
    } else if (dynamic_cast <C *>(p)) {
        std::cout << "Pointer type C " << std::endl;
    }
}

void identify(Base &p) {
    if (dynamic_cast<A *>(&p)){
        std::cout << "Reference type A " << std::endl;
    } else if (dynamic_cast<B *>(&p)) {
        std::cout << "Reference type B " << std::endl;
    } else if (dynamic_cast <C *>(&p)) {
        std::cout << "Reference type C " << std::endl;
    }
}

int main() {

    Base *base;

    base = generate();
    identify(base);
    identify(*base);

    delete base;
}