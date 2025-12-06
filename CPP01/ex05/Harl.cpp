#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ] I like debugging things." << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ] Here is some information." << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ] This might be a problem." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ] Something went really wrong." << std::endl;
}

void Harl::complain(const std::string &level)
{
    typedef void (Harl::*HarlFunc)(void);

    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    HarlFunc    funcs[4]  = { &Harl::debug, &Harl::info,
                              &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*funcs[i])();
            return;
        }
    }
}
