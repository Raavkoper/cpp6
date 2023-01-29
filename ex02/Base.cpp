#include "Base.hpp"

Base::~Base() {}

Base &Base::operator=(const Base &other) {
    return *this;
}

Base *generate(void) {
    int randy = 1 + (rand() % 9);
    if (randy <= 3)
        return (new A);
    else if (randy >= 6)
        return (new B);
    else
        return (new C);
}

void identify(Base *p) {
    std::cout << p << std::endl;
}

void identify(Base &p);