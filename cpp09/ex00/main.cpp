#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	char	*tmp = NULL;
	char	data[] = "test.csv";

	if (argc > 1)
		tmp = argv[1];
	try
	{
		BitcoinExchange	test(data, tmp);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}
