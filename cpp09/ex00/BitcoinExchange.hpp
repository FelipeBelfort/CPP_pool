#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <map>
# include <iostream>
# include <fstream>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_data;
	std::fstream					_db_file;
	std::fstream					_input_file;

	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange	&operator=(const BitcoinExchange &copy);

	void	fillData(void);
	void	parseDate(std::string &str);
	void	parseDataLine(std::string &str);
	void	parseInputLine(std::string &str);
	void	readInput(void);
public:
	BitcoinExchange(char *data, char *input);
	~BitcoinExchange(void);


	class NoDataBaseException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
	class CorrompedDataBaseException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
	class NoInputException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
	class InputErrorException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
	class DuplicatedDataBaseException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
	class NegativeNumberException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
	class TooLargeNumberException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
	class DateNotFoundException : public std::exception
	{
		public:
		const char	*what() const throw();
	};
};


#endif
