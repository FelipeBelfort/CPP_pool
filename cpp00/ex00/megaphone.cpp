#include <iostream>

int	main(int argc, char **argv)
{
	int		    i;
	int		    j;
	int		    max;
    std::string str;

	j = 0;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > 1 && argv && argv[++j])
	{
		i = -1;
        str = argv[j];
        max = str.size();
		while (++i < max)
			std::cout << (char)std::toupper(str.at(i));
	}
	std::cout << std::endl;
	return (0);
}
