#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	char	*tmp = NULL;
	char	data[] = "data.csv";

	if (argc > 1)
		tmp = argv[1];
	try
	{
		// std::cout << tmp << std::endl;
		BitcoinExchange	test(data, tmp);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}
