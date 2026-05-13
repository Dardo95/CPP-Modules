#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form a("A", 50, 40);
    try 
    {
        std::cout << "--- Test 1: Print form A ---" << std::endl;
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Test 2: Ford (grade 45) signs Form A ---" << std::endl;
        Bureaucrat b("Ford", 45);
        std::cout << b << std::endl;
        std::cout << a << std::endl;
        b.signForm(a);
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "--- Test 3: Arthur (grade 150) tries to sign Form A ---" << std::endl;
        Bureaucrat b("Arthur", 150);
        std::cout << b << std::endl;
        std::cout << a << std::endl;
        b.signForm(a);
        std::cout << a << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        std::cout << "--- Test 4: Form with invalid grade ---" << std::endl;
        Form b ("b", 151, 10);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}