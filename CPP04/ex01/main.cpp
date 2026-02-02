/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:25:07 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/02 19:08:14 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== ex01: Array of Animals (half Dog / half Cat) ===" << std::endl;

    const int N = 10;
    const Animal* animals[N];

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

    std::cout << "\n=== ex01: Deep copy test (Dog) ===" << std::endl;

    Dog* d1 = new Dog();
    d1->getBrain()->setIdea(0, "original idea");

    Dog* d2 = new Dog(*d1); // copy constructor

    d1->getBrain()->setIdea(0, "changed idea");

    std::cout << "d1 idea[0]: " << d1->getBrain()->getIdea(0) << std::endl;
    std::cout << "d2 idea[0]: " << d2->getBrain()->getIdea(0) << std::endl;

    delete d1;
    delete d2;

    std::cout << "\n=== ex01 done ===" << std::endl;
    return 0;
}
