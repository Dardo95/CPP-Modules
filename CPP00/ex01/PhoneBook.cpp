#include <iostream>
#include <iomanip>
#include <cctype>
#include "PhoneBook.hpp"

std::string	truncateField(const std::string &field)
{
	if (field.length() <= 10)
		return field;
	else
		return field.substr(0, 9) + ".";
}

PhoneBook::PhoneBook() : count(0), nextIndex(0)
{

}

void	PhoneBook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);

	contacts[nextIndex].setFirstName(firstName);
	contacts[nextIndex].setLastName(lastName);
	contacts[nextIndex].setNickname(nickname);
	contacts[nextIndex].setPhoneNumber(phoneNumber);
	contacts[nextIndex].setDarkestSecret(darkestSecret);

	if (count < 8)
		count++;
	
	nextIndex = (nextIndex + 1) % 8;

	std::cout << "Contact added successfully!" << std::endl;
}

void	PhoneBook::searchContacts() const
{
	if (count == 0)
	{
		std::cout << "No Contact Saved yet" << std::endl;
		return ;
	}

	std::cout	<< std::setw(10) << "Index" << '|'
				<< std::setw(10) << "First Name" << '|'
				<< std::setw(10) << "Last Name" << '|'
				<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::cout	<< std::setw(10) << i << '|'
					<< std::setw(10) << truncateField(contacts[i].getFirstName()) << '|'
					<< std::setw(10) << truncateField(contacts[i].getLastName()) << '|'
					<< std::setw(10) << truncateField(contacts[i].getNickname()) << std::endl;
	}

	std::string searchIndex;

	std::cout << "Enter Index: ";
	if (!std::getline(std::cin, searchIndex))
		return ;
	if (searchIndex.empty())
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	for (size_t i = 0; i < searchIndex.length(); i++)
	{
		if (!std::isdigit(searchIndex[i]))
		{
			std::cout << "Ivalid Index" << std::endl;
			return ;
		}
	}
	int index = 0;
	for (size_t i = 0; i < searchIndex.length(); i++)
		index = index * 10 + (searchIndex[i] - '0');
	if (index < 0 || index >= count)
	{
		std::cout << "Index out of range" << std::endl;
		return ;
	}
	
	const Contact &c = contacts[index];

	std::cout << "First Name: " << c.getFirstName() << std::endl;
	std::cout << "Last Name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}