#include <iostream>

int	main(int argc, char **argv)
{
	int		    			word;
	std::string 			str;
	std::string::iterator	iter;

	word = 0;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argv && argv[++word])
	{
        str = argv[word];
		iter = str.begin();
		while (iter != str.end())
			std::cout << (char)std::toupper(*iter++);
	}
	std::cout << std::endl;
	return (0);
}
