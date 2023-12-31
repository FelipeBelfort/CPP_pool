#include "PhoneBook.hpp"
#include <iostream>

#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"

int	main(int argc, char **argv)
{
	(void)argv;
	std::string	input;
	PhoneBook	pb;
	int			id = 0;

	if (argc != 1)
	{
		std::cout << "Error: The program does not accept any parameters." << std::endl;
		return 1;
	}
	while (input.compare(EXIT))
	{
		std::cout << ">> ";
		std::getline(std::cin, input);
		if (!input.compare(ADD))
		{
			if (id >= MAX_COUNT)
				id = 0;
			if (pb.add_contact(id))
				id++;
		}
		if (!input.compare(SEARCH))
			pb.search_contact();
		if (!std::cin)
			break ;
	}
	return 0;

}
