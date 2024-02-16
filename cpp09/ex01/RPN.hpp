#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>

class RPN
{
private:
	std::stack<int>	_stack;

	void	calculateIt(int c);
public:
	RPN(void);
	RPN(const RPN &copy);
	RPN	&operator=(const RPN &copy);
	~RPN(void);

	void	polishCalculator(std::string str);

	class DivisionByZeroException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
	class InputErrorException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
	class NumberOrOperatorException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
};


#endif
