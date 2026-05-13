#include "Intern.hpp"

int main()
{
    Intern intern;

    
    try 
    {
        std::cout << "--- Test 1: Create ShrubberyCreationForm ---" << std::endl;
        AForm *form = intern.makeForm("shrubbery creation", "Eddie");
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Test 2: Create RobotomyRequestForm ---" << std::endl;
        AForm *form = intern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Test 3: Create PresidentialPardonForm ---" << std::endl;
        AForm *form = intern.makeForm("presidential pardon", "Ford");
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        std::cout << "--- Test 4: Create invalid form ---" << std::endl;
        AForm *form = intern.makeForm("invalid form", "Arthur");
        
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}