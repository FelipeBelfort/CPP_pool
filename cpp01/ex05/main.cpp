#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	test;

	std::cout << "Teste DEBUG: ";
	harl.complain("DEBUG");
	std::cout << "Teste INFO: ";
	harl.complain("INFO");
	std::cout << "Teste WARNING: ";
	harl.complain("WARNING");
	std::cout << "Teste ERROR: ";
	harl.complain("ERROR");

	std::cout << "À ton tour, fais tes tests: ";
	while (std::getline(std::cin, test) && std::cin)
	{
		harl.complain(test);
		std::cout << ">> ";
	}
	return (0);
}