/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:26:41 by enogueir          #+#    #+#             */
/*   Updated: 2026/01/19 09:26:43 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== ClapTrap test ===" << std::endl;
	ClapTrap ct("Clapito");
	ct.attack("Dummy");
	ct.takeDamage(5);
	ct.beRepaired(3);

	std::cout << std::endl;

	std::cout << "=== ScavTrap test ===" << std::endl;
	ScavTrap st("Scavito");
	st.attack("Dummy");
	st.takeDamage(40);
	st.beRepaired(10);
	st.guardGate();

	std::cout << std::endl;

	std::cout << "=== FragTrap basic test ===" << std::endl;
	FragTrap ft("Fraggy");
	ft.attack("Dummy");
	ft.takeDamage(60);
	ft.beRepaired(20);
	ft.highFivesGuys();

	std::cout << std::endl;

	std::cout << "=== FragTrap energy depletion ===" << std::endl;
	for (int i = 0; i < 110; ++i)
		ft.attack("Training dummy");

	std::cout << std::endl;

	std::cout << "=== FragTrap canonical form ===" << std::endl;
	FragTrap copy(ft);   // constructor de copia
	FragTrap assigned;   // constructor por defecto
	assigned = ft;       // operador de asignación

	copy.highFivesGuys();
	assigned.attack("Last dummy");

	std::cout << std::endl;

	std::cout << "=== End of main ===" << std::endl;
	return 0;
}
