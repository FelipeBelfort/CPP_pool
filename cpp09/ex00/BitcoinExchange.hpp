#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <map>
# include <iostream>
# include <fstream>

# define DEBUG std::cout << "pas moi" << std::endl;
// # define DATA true
// # define INPUT false

class BitcoinExchange
{
private:
	std::map<std::string, float>	_data;
	// std::map<std::string, double>	_input;
	std::fstream					_db_file;
	std::fstream					_input_file;

	BitcoinExchange(void);
public:
	BitcoinExchange(char *data, char *input);
	~BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange	&operator=(const BitcoinExchange &copy);


	void		fillData(void);
	std::string	parseDate(std::string str);
	void		parseDataLine(std::string str);
	void		parseInputLine(std::string str);
	void		readInput(void);

	class NoDataBaseException : public std::exception
	{
		const char	*what() const throw();
	};
	class NoInputException : public std::exception
	{
		const char	*what() const throw();
	};
	class InputErrorException : public std::exception
	{
		const char	*what() const throw();
	};
	class DuplicatedDataBaseException : public std::exception
	{
		const char	*what() const throw();
	};
	// class NoDataBaseException : public std::exception
	// {
	// 	const char	*what() const throw();
	// };
	// class NoDataBaseException : public std::exception
	// {
	// 	const char	*what() const throw();
	// };
	// class NoDataBaseException : public std::exception
	// {
	// 	const char	*what() const throw();
	};
};


#endif
