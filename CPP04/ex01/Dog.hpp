/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:25:01 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/02 19:03:15 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Brain;
class Dog : public Animal
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
