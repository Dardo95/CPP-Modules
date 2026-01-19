/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:03:39 by enogueir          #+#    #+#             */
/*   Updated: 2025/12/11 12:50:10 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: _name("dafault"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " cannot attack because it has no hit points left!"
				  << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " cannot attack because it has no energy points left!"
				  << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name
			  << " attacks " << target
			  << ", causing " << _attackDamage
			  << " points of damage! (Energy left: " << _energyPoints << ")"
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " is already at 0 hit points and cannot take more damage."
				  << std::endl;
		return;
	}

	if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name
				  << " takes " << amount
				  << " points of damage and is now destroyed!"
				  << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name
				  << " takes " << amount
				  << " points of damage (HP left: " << _hitPoints << ")"
				  << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " cannot be repaired because it has 0 hit points!"
				  << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " cannot be repaired because it has no energy points left!"
				  << std::endl;
		return;
	}

	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name
			  << " repairs itself for " << amount
			  << " hit points (HP: " << _hitPoints
			  << ", Energy: " << _energyPoints << ")"
			  << std::endl;
}