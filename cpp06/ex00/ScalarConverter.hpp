#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cmath>
# include <cctype>

# define T_VOID 0
# define T_CHAR 1
# define T_INT 2
# define T_FLOAT 3
# define T_DOUBLE 4

typedef	void	(*func)(char *);

class ScalarConverter
{
private:
	ScalarConverter(void);
	~ScalarConverter(void);
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
public:
	static void	convert(char *input);
};




#endif
