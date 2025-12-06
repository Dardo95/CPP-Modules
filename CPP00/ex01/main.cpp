#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook pb;
	std::string command;

	while(true)
	{
		std::cout << "Choose command ADD, SEARCH, EXIT" << std::endl;
		if (!std::getline(std::cin, command))
				break;

		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContacts();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}