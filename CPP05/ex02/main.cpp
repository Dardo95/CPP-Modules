#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form a("A", 50, 40);
    try 
    {
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Ford", 45);
        std::cout << b << std::endl;
        b.signForm(a);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("Arthur", 150);
        std::cout << b << std::endl;
        b.signForm(a);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        Form b ("b", 151, 10);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}