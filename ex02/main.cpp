#include "Base.hpp"

int main() {
    {
        Base *random1;
        Base *random2;
        Base *random3;

        random1 = generate();
        random2 = generate();
        random3 = generate();

        A *a_object = new A;
        B *b_object = new B;
        C *c_object = new C;

        std::cout << "Testing the set values" << std::endl;
        std::cout << std::endl;

        identify(b_object);
        identify(a_object);
        identify(c_object);

        std::cout << std::endl;
        std::cout << "Testing the random values" << std::endl;
        std::cout << std::endl;

        identify(random1);
        identify(random2);
        identify(random3);
    }
    {
        A a_object;
        B b_object;
        C c_object;

        std::cout << std::endl;
        std::cout << "Testing the set values" << std::endl;
        std::cout << std::endl;

        identify(c_object);
        identify(b_object);
        identify(a_object);
    }
}