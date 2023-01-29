#include "Serialize.hpp"

int main(void) {
    Data *data = new Data;
    data->str = "Wassup dude";
    uintptr_t intptr = serialize(data);
    
    std::cout << &intptr << std::endl;
    std::cout << &data << std::endl;
    std::cout << std::endl;

    intptr = serialize(data);
    data = NULL;
    data = deserialize(intptr);

    std::cout << data->str << std::endl;
}