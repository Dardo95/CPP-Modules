/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:34:40 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/02 19:03:51 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	type = "Dog";
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Brain* Dog::getBrain() const
{
    return brain;
}

void Dog::makeSound() const
{
	std::cout << "* Woof Wooof *" << std::endl;
}
