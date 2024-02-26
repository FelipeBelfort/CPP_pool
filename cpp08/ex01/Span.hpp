#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>

class Span
{
private:
	size_t			_max_size;
	std::list<int>	_lst;

public:
	Span(size_t nb = 0);
	~Span(void);
	Span(const Span &copy);
	Span &operator=(const Span &copy);

	void	addRangeOfNumbers(const std::vector<int>::iterator begin, const std::vector<int>::iterator end);

	void	addNumber(int nb);
	int		shortestSpan(void);
	int		longestSpan(void);

	class ExceedSizeOfListException : public std::exception
	{
		public:
		virtual const char	*what() const throw();
	};
	class NoNumbersStoredException : public std::exception
	{
		public:
		virtual const char	*what() const throw();
	};
	class OnlyOneNumberStoredException : public std::exception
	{
		public:
		virtual const char	*what() const throw();
	};

};

#endif
