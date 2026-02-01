/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogueir <enogueir@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:25:07 by enogueir          #+#    #+#             */
/*   Updated: 2026/02/01 18:12:47 by enogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Correct polymorphism ===" << std::endl;

    const Animal* a = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();

    std::cout << "a type: " << a->getType() << std::endl;
    std::cout << "d type: " << d->getType() << std::endl;
    std::cout << "c type: " << c->getType() << std::endl;

    std::cout << "a sound: ";
    a->makeSound();
    std::cout << "d sound: ";
    d->makeSound();
    std::cout << "c sound: ";
    c->makeSound();

    std::cout << "Deleting via Animal* (must call derived destructors)..." << std::endl;
    delete a;
    delete d;
    delete c;

    std::cout << "\n=== Wrong polymorphism (no virtual) ===" << std::endl;

    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << "wa type: " << wa->getType() << std::endl;
    std::cout << "wc type: " << wc->getType() << std::endl;

    std::cout << "wa sound: ";
    wa->makeSound();
    std::cout << "wc sound (should be WrongAnimal sound): ";
    wc->makeSound();

    std::cout << "Deleting via WrongAnimal* ..." << std::endl;
    delete wa;
    delete wc;

    return 0;
}
