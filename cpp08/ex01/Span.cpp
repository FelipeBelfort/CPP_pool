#include "Span.hpp"

Span::Span(size_t nb) : _max_size(nb)
{
}

Span::~Span(void)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span	&Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		if (!this->_lst.empty())
			this->_lst.clear();
		this->_max_size = copy._max_size;
		this->_lst = copy._lst;
	}
	return *this;
}

int		Span::longestSpan(void)
{
	if (this->_lst.empty())
		throw NoNumbersStoredException();
	if (this->_lst.size() == 1)
		throw OnlyOneNumberStoredException();
	std::list<int>	tmp(this->_lst);
	tmp.sort();
	return (abs(abs(tmp.back()) - abs(tmp.front())));
}

int		Span::shortestSpan(void)
{
	std::list<int>	tmp;
	std::list<int>::iterator i;
	int				shortest_span;

	if (this->_lst.empty())
		throw NoNumbersStoredException();
	if (this->_lst.size() == 1)
		throw OnlyOneNumberStoredException();
	if (this->_lst.size() == 2)
		return (this->longestSpan());
	tmp = this->_lst;
	tmp.sort();
	tmp.reverse();
	i = tmp.begin();
	shortest_span = abs(*i - *++i);
	while (i != tmp.end())
	{
		int	tmp_int = *(i++);
		if (i == tmp.end())
			break ;
		int	tmp_span = abs(tmp_int - *i);
		if (tmp_span < shortest_span)
			shortest_span = tmp_span;
	}
	return shortest_span;
}

void	Span::addNumber(int nb)
{
	if (this->_lst.size() == this->_max_size)
		throw ExceedSizeOfListException();
	this->_lst.push_back(nb);
}

void	Span::addRangeOfNumbers(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
	for (std::vector<int>::const_iterator i = begin; i != end; i++)
		addNumber(*begin);
	
}

const char	*Span::ExceedSizeOfListException::what() const throw()
{
	return "Error: You are attempting to exceed the limit of the list";
}

const char	*Span::NoNumbersStoredException::what() const throw()
{
	return "Error: There are no numbers stored";
}

const char	*Span::OnlyOneNumberStoredException::what() const throw()
{
	return "Error: There are only one number in the list";
}
