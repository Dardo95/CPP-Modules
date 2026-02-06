/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:25:07 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/06 14:52:28 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== ex02: Array of Animals (half Dog / half Cat) ===" << std::endl;

    const int N = 10;
    const AAnimal* animals[N];

    int i = 0;
    while (i < N)
    {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        i++;
    }

    std::cout << "\nDeleting animals via Animal* ..." << std::endl;

    i = 0;
    while (i < N)
    {
        delete animals[i];
        i++;
    }

    std::cout << "\n=== ex02: Deep copy test (Dog) ===" << std::endl;

    Dog* d1 = new Dog();
    d1->getBrain()->setIdea(0, "original idea");

    Dog* d2 = new Dog(*d1); 

    d1->getBrain()->setIdea(0, "changed idea");

    std::cout << "d1 idea[0]: " << d1->getBrain()->getIdea(0) << std::endl;
    std::cout << "d2 idea[0]: " << d2->getBrain()->getIdea(0) << std::endl;

    delete d1;
    delete d2;

    std::cout << "\n=== ex02 done ===" << std::endl;
    return 0;
}