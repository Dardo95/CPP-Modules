/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:26:01 by enogueir          #+#    #+#             */
/*   Updated: 2026/01/19 09:26:04 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== ClapTrap tests ===" << std::endl;
    ClapTrap ct("Clapito");

    ct.attack("Dummy");
    ct.takeDamage(5);
    ct.beRepaired(3);

    std::cout << std::endl;

    std::cout << "=== ScavTrap basic tests ===" << std::endl;
    ScavTrap st("Scavito");

    st.attack("Dummy");
    st.takeDamage(40);
    st.beRepaired(10);
    st.guardGate();

    std::cout << std::endl;

    std::cout << "=== ScavTrap energy depletion ===" << std::endl;
    for (int i = 0; i < 60; ++i)
        st.attack("Training dummy");

    std::cout << std::endl;

    std::cout << "=== ScavTrap canonical form ===" << std::endl;
    ScavTrap copy(st);
    ScavTrap assigned;
    assigned = st;

    copy.guardGate();
    assigned.attack("Last dummy");

    std::cout << std::endl;

    std::cout << "=== End of main ===" << std::endl;
    return 0;
}
