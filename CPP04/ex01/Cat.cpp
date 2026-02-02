/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:34:40 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/02 19:04:00 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	type = "Cat";
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Brain* Cat::getBrain() const
{
    return brain;
}

void Cat::makeSound() const
{
	std::cout << "* Miau Miau *" << std::endl;
}
