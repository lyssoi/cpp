#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "time.h"

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
    

}

void identify(Base &p) {
    
}

int main() {

}