#include "ScalarConverter.hpp"



ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

static	void	showVoid(char *input)
{
	(void)input;
	std::cout << "char: impossible\n"
					"int: impossible\n"
					"float: nanf\n"
					"double: nan" << std::endl;
}

static void	showChar(char *input)
{
	char	c = input[0];

	std::cout << "char: '"<< c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void displayChar(int nb)
{
	std::cout << "char: ";
	 if (nb < 0 || nb > 255)
		std::cout << "impossible";
	else if (!std::isprint(nb))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(nb) << "'";
	std::cout << std::endl;
}

static void displayInt(double nb)
{
	std::cout << "int: ";
	if (nb < INT_MIN || nb > INT_MAX || nb != nb)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(nb);
	std::cout << std::endl;
}

static void	displayFloat(double nb)
{
	std::cout << "float: ";
	if (nb != nb)
		std::cout << "nan";
	else
		std::cout << static_cast<float>(nb);
	if (nb < 1000000 && nb > -1000000)
		if (nb - static_cast<int>(nb) == 0)
			std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void	displayDouble(double nb)
{
	std::cout << "double: ";
	if (nb != nb)
		std::cout << "nan";
	else
		std::cout << nb;
	if (nb < 1000000 && nb > -1000000)
		if (nb - static_cast<int>(nb) == 0)
			std::cout << ".0";
	std::cout << std::endl;
}

static void	showInt(char *input)
{
	int	nb = atoi(input);

	displayChar(nb);
	std::cout << "int: " << nb << "\n";
	displayFloat(nb);
	displayDouble(nb);
}

static void	showFloat(char *input)
{
	float	nb = atof(input);

	displayChar(nb);
	displayInt(nb);
	displayFloat(nb);
	displayDouble(nb);
}

static void	showDouble(char *input)
{
	char	*ptr = NULL;
	double	nb = strtod(input, &ptr);

	displayChar(nb);
	displayInt(nb);
	displayFloat(nb);
	displayDouble(nb);
}

static bool	isValid(char *input, char *ptr, double value)
{
	std::string	tmp_ptr = ptr;
	std::string	tmp_input = input;
	size_t		len_input = tmp_input.length();

	if (!len_input || (!value && len_input > 1) || (ptr && tmp_ptr.length() > 1) || (value && *ptr && tmp_ptr.at(0) != 'f'))
		return false;
	return true;
}

static int	findType(char *input)
{
	char	*ptr = NULL;
	double	value = strtod(input, &ptr);
	int		value_int = atoi(input);

	if (!input[0] || !isValid(input, ptr, value))
		return T_VOID;
	if (!value && ptr && input[0] == ptr[0])
		return T_CHAR;
	if (ptr && ptr[0] == 'f' && !ptr[1])
		return T_FLOAT;
	if ( value >= INT_MIN && value <= INT_MAX && value - value_int == 0)
		return T_INT;
	return T_DOUBLE;
}

static	char *trim(char *input)
{
	size_t	i = 0;

	while (std::isspace(input[i]))
		i++;
	if (!input[i])
		i = 0;
	return &input[i];
}

void	ScalarConverter::convert(char *input)
{
	func	f[] = {&showVoid, &showChar, &showInt, &showFloat, &showDouble};
	int		result;

	input = trim(input);
	result = findType(input);
	f[result](input);
}
