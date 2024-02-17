#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(char *data, char *input)
{
	if (!data || !input)
		return ;
	this->_db_file.open(data);
	if (!this->_db_file.is_open())
		return ;
	(void)input;
	// this->_input_file.open(input);
	// if (!this->_input_file.is_open())
	// {
	// 	this->_db_file.close();
	// 	return ;
	// }
	this->fillData();
	// this->fillMap(DATA);
	// this->fillMap(INPUT);
	this->_db_file.close();
	// this->_input_file.close();

}

BitcoinExchange::~BitcoinExchange()
{

}

void	BitcoinExchange::fillData()
{
	std::string	tmp;

		// std::map<std::string, double>::iterator	it = this->_data.begin();
	while (std::getline(this->_db_file, tmp))
	{
		this->parseDataLine(tmp);
	}

}

void	BitcoinExchange::parseDataLine(std::string str)
{
	std::string												key;
	std::pair<std::map<std::string, float>::iterator, bool>	ret;

	// std::cout << "size => " << str.size() << " str[10] => " << str[10] << " not of => " << str.find_first_not_of("-0123456789,.") << " first of => " << str.find_first_of("0123456789", 11) << std::endl;
	if (str.size() < 12 || str[10] != ',' || str.find_first_not_of("-0123456789,.") != std::string::npos || str.find_first_of("0123456789", 11) != 11)
		return ;
	// std::cout << "data => " << str.substr(0, 10) << std::endl;
	key = this->parseDate(str.substr(0, 10));
	if (key.empty())
		return ;
	ret = this->_data.insert(std::pair<std::string, double>(key, std::atof(str.c_str() + 11)));
	std::cout << (*ret.first).first << " => " << this->_data[key] << "#" << std::atof(str.c_str() + 11) << std::endl;
	if (ret.second == false)
		return ;
}

std::string	BitcoinExchange::parseDate(std::string str)
{
	int	year;
	int	month;
	int	day;

	// if (str.size() != 10)
	// 	return NULL;
	if (str[4] != '-' || str[7] != '-')
		return NULL;
	// str[4] = '#';
	// str[7] = '#';
	// std::cout << "a => " << str.find_first_not_of("0123456789-") << " b => " << str.find_first_of("-") << " c => " << str.find_first_of("-", 5) << " d => " << str.find_first_of("-", 8) << std::endl;
	if (str.find_first_not_of("0123456789-") != std::string::npos || str.find_first_of("-") != 4
		|| str.find_first_of("-", 5) != 7 || str.find_first_of("-", 8) != std::string::npos)
		return NULL;
	year = atoi(str.c_str());
	month = atoi(str.c_str() + 5);
	day = atoi(str.c_str() + 8);

	if (year < 2008 || year > 2024)
		return NULL;
	if (month < 1 || month > 12)
		return NULL;
	if (day < 1)
		return NULL;
	// DEBUG
	if (month == 2)
	{
		if (day > 29 && ((year % 400 == 0) || ( (year % 4 == 0) && (year % 100 != 0))))
			return NULL;
		else if (day > 28)
			return NULL;
	}
	if ((month < 8 && month % 2) || (month > 7 && month % 2 == 0))
		if (day > 31)
			return NULL;
	if ((month < 8 && month % 2 == 0) || (month > 7 && month % 2))
		if (day > 30)
			return NULL;
	// str[4] = '#';
	// str[7] = '#';
	return str;
}


// 2012-01-11 | a
