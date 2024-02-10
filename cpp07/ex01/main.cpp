#include <iostream>
#include "iter.hpp"

template <typename T>
void	testprint(T arg)
{
	std::cout << arg << std::endl;
}

int main()
{
	std::string	lst_str[] = {"Hello", "je", "suis", "un", "test"};
	char		str[] = "Moi aussi";
	int			lst_int[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	iter(lst_str, 5, testprint);
	std::cout << std::endl;
	iter(str, 9, testprint);
	std::cout << std::endl;
	iter(lst_int, 11, testprint);

	return 0;
}
