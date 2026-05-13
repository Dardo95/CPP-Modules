#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

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

void ShrubberyCreationForm::executeAction() const
{
        std::ofstream file((_target + "_shrubbery").c_str());
    file << "          .          " << std::endl;
    file << "         /|\\         " << std::endl;
    file << "        / | \\        " << std::endl;
    file << "       /  |  \\       " << std::endl;
    file << "      / . | . \\      " << std::endl;
    file << "     /  /\\|/\\  \\     " << std::endl;
    file << "    /  /  |  \\  \\    " << std::endl;
    file << "   /  / . | . \\  \\   " << std::endl;
    file << "  /  /  / | \\  \\  \\  " << std::endl;
    file << " /  /  /  |  \\  \\  \\ " << std::endl;
    file << "/___/__/___|___\\__\\___\\" << std::endl;
    file << "          |||          " << std::endl;
    file << "          |||          " << std::endl;
    file << "          |||          " << std::endl;
    file.close();
 
}