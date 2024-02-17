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
	std::map<std::string, double>	_input;
	std::fstream					_db_file;
	std::fstream					_input_file;
public:
	BitcoinExchange(char *data, char *input);
	~BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange	&operator=(const BitcoinExchange &copy);


	void		fillData();
	std::string	parseDate(std::string str);
	void		parseDataLine(std::string str);
};


#endif
