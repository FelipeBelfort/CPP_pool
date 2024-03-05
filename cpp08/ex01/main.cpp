#include "Span.hpp"

int main()
{

	std::vector<int>	to_test;
	for (size_t i = 0; i < 900; i++)
		to_test.push_back(i + i);
	
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest span " << sp.shortestSpan() << std::endl;
	std::cout << "longest span " << sp.longestSpan() << std::endl;
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
		sp.addRangeOfNumbers(to_test.begin(), to_test.begin() + 1);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	sp.addRangeOfNumbers(to_test.begin(), to_test.end());
	std::cout << "shortest span " << sp.shortestSpan() << std::endl;
	std::cout << "longest span " << sp.longestSpan() << std::endl;

	return 0;
}
