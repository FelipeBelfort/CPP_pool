#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	calculator;

	if (argc != 2)
	{
		std::cout << "Error: Expected <executable> <string with arguments>" << std::endl;
		return 1;
	}
	try
	{
		calculator.polishCalculator(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}
