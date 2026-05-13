#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &src)
    {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "DRRRRRR... BZZZZZ... DRRRRRR..." << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized!" << std::endl;
    else
        std::cout << _target << " robotomy failed!" << std::endl;
}