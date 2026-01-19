/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:28:34 by enogueir          #+#    #+#             */
/*   Updated: 2025/12/11 13:22:52 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Kaladin");
    ClapTrap b("Szeth");
    ClapTrap c(a);
    ClapTrap d;
    d = b;

	c.attack("Szeth");

    a.attack("Szeth");
    b.takeDamage(3);
    b.beRepaired(2);

    for (int i = 0; i < 10; ++i)
        a.attack("Szeth");

    a.attack("Szeth");
    a.beRepaired(5);

    b.takeDamage(20);
    b.attack("Kaladin");
    b.beRepaired(5);
    return 0;
}


