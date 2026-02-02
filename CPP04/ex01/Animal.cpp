/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:55:45 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/01 17:27:17 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
	: type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "* generic animal sound *" << std::endl;
}