/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:24:08 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/06 14:47:44 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# include <string>

class AAnimal
{
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    std::string getType() const;

    virtual void makeSound() const = 0;
};

#endif
