#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <map>
# include <iostream>
# include <fstream>

# define DATA true
# define INPUT false

class BitcoinExchange
{
private:
	std::map<std::string, double>	_data;
	std::map<std::string, double>	_input;
	std::fstream					_db_file;
	std::fstream					_input_file;
public:
	BitcoinExchange(char *data = ".", char *input = ".");
	~BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange	&operator=(const BitcoinExchange &copy);


	void	fillMap(bool data);
	void	parseDate()
};

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}



#endif
