#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon)
    : name(name), weapon(weapon)
{
}

void HumanA::attack(void) const
{
    std::cout << this->name
              << " attacks with their "
              << this->weapon.getType()
              << std::endl;
}
