#include <iostream>
#include "whatever.hpp"

template <typename T>
void	testTemplate(T &arg1, T &arg2)
{

	std::cout << "Before swap\narg1 = " << arg1 << std::endl;
	std::cout << "arg2 = " << arg2 << std::endl;
	swap(arg1, arg2);
	std::cout << "After swap\narg1 = " << arg1 << std::endl;
	std::cout << "arg2 = " << arg2 << std::endl;
	std::cout << "min = " << min(arg1, arg2) << "\nmax = " << max(arg1, arg2) << std::endl;
}

int main()
{
	std::string	a = "testing template";
	std::string	b = "not testing template";
	int			c = 3;
	int			d = -17;
	size_t		e = 0;
	size_t		f = 43;

	testTemplate(a, b);
	testTemplate(c, d);
	testTemplate(e, f);
	return 0;
}
