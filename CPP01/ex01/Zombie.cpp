#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
}

Zombie::Zombie(const std::string &name) : name(name)
{
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name)
{
    this->name = name;
}
