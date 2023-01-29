#include "Base.hpp"

int main() {
    Base *homer;
    Base *bart;
    Base *marge;

    homer = generate();
    bart = generate();
    marge = generate();

    identify(homer);
    identify(bart);
    identify(marge);
}