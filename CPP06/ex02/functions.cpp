#include "functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    srand(time(NULL));
    int r = rand() % 3;
    std::cout << "Generated: " << r << std::endl;
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; }
    catch (std::exception&) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; }
    catch (std::exception&) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; }
    catch (std::exception&) {}
}