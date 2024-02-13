#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <list>

class Span
{
private:
	size_t			_max_size;
	// int				_max;
	// int				_min;
	std::list<int>	_lst;

public:
	Span(size_t nb = 0);
	~Span(void);
	Span(const Span &copy);
	Span &operator=(const Span &copy);

	void	addNumber(int nb);
	int		shortestSpan(void);
	int		longestSpan(void);
	void	addRangeOfNumbers(size_t amount);

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
