#include <iostream>
#include "Base.hpp"
#include "functions.hpp"

int main()
{
    Base* p = generate();

    std::cout << "By pointer:   ";
    identify(p);

    std::cout << "By reference: ";
    identify(*p);

    delete p;
    return 0;
}