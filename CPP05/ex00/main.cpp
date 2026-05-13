#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "--- Test 1: Ford increments and decrements grade ---" << std::endl;
        Bureaucrat b("Ford", 50);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Test 2: Zaphod with invalid grade 0 ---" << std::endl;
        Bureaucrat b("Zaphod", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Test 3: Arthur with invalid grade 151 ---" << std::endl;
        Bureaucrat b("Arthur", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Test 4: Zaphod at grade 1 tries to increment ---" << std::endl;
        Bureaucrat b("Zaphod", 1);
        std::cout << b << std::endl;
        b.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}