#include "Span.hpp"

Span::Span(size_t nb) : _max_size(nb)//, _max(-2147483648), _min(2147483647)
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
	this->_lst.clear();
	this->_max_size = copy._max_size;
	for (std::list<int>::const_iterator i = copy._lst.begin(); i != copy._lst.end(); i++)
		this->_lst.push_back(*i);
	return *this;
}

int		Span::longestSpan(void)
{
	int				size = this->_lst.size();
	std::list<int>	tmp(this->_lst);

	if (!size)
		throw NoNumbersStoredException();
	if (size == 1)
		throw OnlyOneNumberStoredException();
	tmp.sort();
	return (abs(abs(*(tmp.begin())) - abs(*(tmp.end()))));
}

int		Span::shortestSpan(void)
{
	std::list<int>	tmp(this->_lst);
	int				size = this->_lst.size();
	int				a = 0;
	int				b;

	if (!size)
		throw NoNumbersStoredException();
	if (size == 1)
		throw OnlyOneNumberStoredException();
	if (size == 2)
		return (this->longestSpan());
	tmp.unique();
	tmp.sort();
	tmp.reverse();
	for (std::list<int>::iterator i = tmp.begin(); i != tmp.end(); i++)
	{
		b = abs((*i++) - *(i--));
		if (!a || b < a)
			a = b;
	}
	return a;
}

void	Span::addNumber(int nb)
{
	if (this->_lst.size() == this->_max_size)
		throw ExceedSizeOfListException();
	this->_lst.push_back(nb);
}

void	Span::addRangeOfNumbers(size_t amount)
{
	srand(time(0));
	if (this->_lst.size() + amount > this->_max_size)
		throw ExceedSizeOfListException();
	for (size_t i = 0; i < amount; i++)
		this->_lst.push_back(rand());
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
