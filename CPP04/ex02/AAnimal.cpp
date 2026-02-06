/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:55:45 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/06 14:46:43 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
	: type(other.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}

void AAnimal::makeSound() const
{
	std::cout << "* generic AAnimal sound *" << std::endl;
}