#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(char *data, char *input)
{
	this->_db_file.open(data);
	if (!this->_db_file.is_open())
		return ;
	this->_input_file.open(input);
	if (!this->_input_file.is_open())
	{
		this->_db_file.close();
		return ;
	}
	this->fillMap(DATA);
	this->fillMap(INPUT);
	this->_db_file.close();
	this->_input_file.close();

}

void	BitcoinExchange::parseDate(std::string str)
{
	int	year;
	int	month;
	int	day;

	if (str.size() != 10)
		return ;
	if (str.find_first_not_of("0123456789-") != std::string::npos)
		return ;
	if (str[4] != '-' || str[7] != '-')
		return ;
	str[4] = '#';
	str[7] = '#';
	if (str.find_first_not_of("0123456789#") != std::string::npos)
		return ;
	year = atoi(str.c_str());
	month = atoi(str.c_str());
	day = atoi(str.c_str());

	if (year < 2008 || year > 2024)
		return ;
	if (month < 1 || month > 12)
		return ;
	if (day < 1)
		return ;
	if (month == 2)
	{
		if (day > 29 && (year % 400 == 0) || ( (year % 4 == 0) && (year % 100 != 0) ))
			return ;
		else if (day > 28)
			return ;
	}
	if ((month < 8 && month % 2) || (month > 7 && month % 2 == 0))
		if (day > 31)
			return ;
	if ((month < 8 && month % 2 == 0) || (month > 7 && month % 2))
		if (day > 30)
			return ;

}


// 2012-01-11 | a
