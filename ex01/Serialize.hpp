#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <iostream>

struct Data {
    std::string str;
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);
#endif