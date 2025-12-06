#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
    : name(name), weapon(NULL)
{
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack(void) const
{
    if (this->weapon == NULL)
        return;

    std::cout << this->name
              << " attacks with their "
              << this->weapon->getType()
              << std::endl;
}
