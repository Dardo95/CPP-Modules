/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:04:11 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/02 19:10:23 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
# include <iostream>
# include <string>

Brain::Brain()
{
	std::cout << "Brain default contructor called" << std::endl;
	for (int i = 0; i < 100 ;i++)
		ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy contructor called" << std::endl;
	for (int i = 0; i < 100 ;i++)
		this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100 ;i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

const std::string &Brain::getIdea(int index) const
{
	static const std::string empty = "";
	if (index < 0 || index >= 100)
		return empty;
	return ideas[index];
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
		return;
	ideas[index] = idea;
}