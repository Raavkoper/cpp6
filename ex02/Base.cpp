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
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);

    if (a) std::cout << "Object is of type: A" << std::endl;
    if (b) std::cout << "Object is of type: B" << std::endl;
    if (c) std::cout << "Object is of type: C" << std::endl;
}

void identify(Base &p) {
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << "Object is of type: A" << std::endl;
    } catch (std::exception &e) {}
    try {
        B b = dynamic_cast<B&>(p);
        std::cout << "Object is of type: B" << std::endl;
    } catch (std::exception &e) {}
    try {
        C c = dynamic_cast<C&>(p);
        std::cout << "Object is of type: C" << std::endl;
    } catch (std::exception &e) {}
}