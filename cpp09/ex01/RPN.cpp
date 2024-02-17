#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::~RPN(void)
{
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN	&RPN::operator=(const RPN &copy)
{
	this->_stack = copy._stack;
	return *this;
}

void	RPN::calculateIt(int c)
{
	int	last;
	int	first;
	int	result;

	if (this->_stack.size() < 2)
		throw NumberOrOperatorException();
	last = this->_stack.top();
	this->_stack.pop();
	first = this->_stack.top();
	this->_stack.pop();
	switch (c)
	{
	case '-':
		result = first - last;
		break;
	case '+':
		result = first + last;
		break;
	case '*':
		result = first * last;
		break;
	case '/':
		if (!last)
			throw DivisionByZeroException();
		result = first / last;
		break;
	}
	this->_stack.push(result);
}

void	RPN::polishCalculator(std::string str)
{
	if (str.empty() || str.find_first_not_of(" 0123456789-+*/") != std::string::npos || (str.size() == 1 && str.find_first_of("-+/*") != std::string::npos))
		throw InputErrorException();
	if (str.size() == 1)
		std::cout << static_cast<int>(str[0] - '0') << std::endl;
	for (size_t i = str.find_first_not_of(" "); i != std::string::npos; i = str.find_first_not_of(" ", i))
	{
		if (str.find_first_of("-+/*", i) == i)
			calculateIt(str.at(i));
		else
			this->_stack.push(atoi(str.c_str() + i));
		i++;
	}
	if (this->_stack.size() != 1)
		throw NumberOrOperatorException();
	std::cout << this->_stack.top() << std::endl;
}

const char	*RPN::DivisionByZeroException::what() const throw()
{
	return "Error: division by zero is not allowed";
}

const char	*RPN::InputErrorException::what() const throw()
{
	return "Error";
}

const char	*RPN::NumberOrOperatorException::what() const throw()
{
	return "Error: there are not enough numbers or operators to do the operation";
}


