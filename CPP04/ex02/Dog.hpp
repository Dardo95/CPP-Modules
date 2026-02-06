/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:25:01 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/06 14:48:26 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Brain;
class Dog : public AAnimal
{
private:
	Brain* brain;
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

	Brain* getBrain() const;
    virtual void makeSound() const;
};

#endif
