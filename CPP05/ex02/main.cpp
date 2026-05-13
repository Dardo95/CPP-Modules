#include "AForm.hpp"
// #include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat a("Zaphod", 2);
    ShrubberyCreationForm   scf("Eddie");
    RobotomyRequestForm     rrf("Arthur");
    PresidentialPardonForm  ppf("Ford");
    
    try 
    {
        std::cout << "--- Test 1: Zaphod signs and executes ShrubberyCreationForm ---" << std::endl;
        std::cout << a << std::endl;
        std::cout << scf << std::endl;
        a.signForm(scf);
        std::cout << scf << std::endl;
        a.executeForm(scf);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Test 2: Zaphod signs and executes RobotomyRequestForm ---" << std::endl;
        std::cout << a << std::endl;
        std::cout << rrf << std::endl;
        a.signForm(rrf);
        std::cout << rrf << std::endl;
        a.executeForm(rrf);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Test 3: Zaphod signs and executes PresidentailPardonForm ---" << std::endl;
        std::cout << a << std::endl;
        std::cout << ppf << std::endl;
        a.signForm(ppf);
        std::cout << ppf << std::endl;
        a.executeForm(ppf);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        std::cout << "--- Test 4: Marvin (grade 150) tries to sign and execute ShrubberyCreationForm ---" << std::endl;
        Bureaucrat marvin ("Marvin", 150);
        std::cout << marvin << std::endl;
        std::cout << scf << std::endl;
        marvin.signForm(scf);
        marvin.executeForm(scf);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "--- Test 5: Trying to execute unsigned form ---" << std::endl;
        ShrubberyCreationForm scf2("Trillian");
        std::cout << scf2 << std::endl;
        a.executeForm(scf2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}