#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &src)
    {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}