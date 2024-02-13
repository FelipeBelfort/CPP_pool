#include "Span.hpp"

int main()
{

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(8);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	Span	sp2(1000000000);
	sp = sp2;

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		sp.addRangeOfNumbers(1);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	sp.addRangeOfNumbers(10000);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
