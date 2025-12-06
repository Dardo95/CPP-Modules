#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string s = argv[i];
			for (size_t j = 0; j < s.length(); j++)
			{
				unsigned char ch = static_cast<unsigned char>(s[j]);
				char upper = static_cast<char>(std::toupper(ch));
				std::cout << upper;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}