#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base {
public:
    virtual ~Base();
    Base &operator=(const Base &other);
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif