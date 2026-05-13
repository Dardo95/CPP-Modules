#include "Intern.hpp"

struct FormEntry
{
    std::string name;
    AForm       *(*create)(std::string const &);
};

Intern::Intern()
{
    std::cout << "Constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
    (void)src;
    std::cout << "Constructor copy called" << std::endl;
}

Intern &Intern::operator=(Intern const & src)
{
    (void)src;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Destructor called" << std::endl;
}

static AForm *createShrubbery(std::string const & target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(std::string const & target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPardon(std::string const & target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const & formName, std::string const & target) const
{
    FormEntry forms[] = {
    {"shrubbery creation", createShrubbery},
    {"robotomy request",   createRobotomy},
    {"presidential pardon", createPardon}
    };

    for (int i = 0; i < 3; i++)
    {    
        if (forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }
    std::cout << "Error: form '" << formName << "' does not exist" << std::endl;
    return NULL;
}