#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(char *data, char *input)
{
	if (!data)
		throw NoDataBaseException();
	if (!input)
		throw NoInputException();
	this->_db_file.open(data);
	if (!this->_db_file.is_open())
		throw NoDataBaseException();
	this->_input_file.open(input);
	if (!this->_input_file.is_open())
	{
		this->_db_file.close();
		throw NoInputException();
	}
	this->fillData();
	this->readInput();
}

BitcoinExchange::~BitcoinExchange(void)
{
	this->_db_file.close();
	this->_input_file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		this->_data = copy._data;
	return *this;
}

void	BitcoinExchange::fillData(void)
{
	std::string	tmp;

	while (std::getline(this->_db_file, tmp))
		this->parseDataLine(tmp);
}

void	BitcoinExchange::parseDataLine(std::string &str)
{
	std::string												key;
	std::pair<std::map<std::string, float>::iterator, bool>	ret;
	float													nb;

	if (str == "date,exchange_rate")
		return ;
	if (str.size() < 12 || str[10] != ',' || str.find_first_not_of("-0123456789,.") != std::string::npos || str.find_first_of("0123456789", 11) != 11)
		throw CorrompedDataBaseException();
	key = str.substr(0, 10);
	try
	{
		this->parseDate(key);
	}
	catch(const std::exception& e)
	{
		throw CorrompedDataBaseException();
	}
	nb = std::atof(str.c_str() + 11);
	if (nb < 0)
		throw CorrompedDataBaseException();
	ret = this->_data.insert(std::pair<std::string, double>(key, nb));
	if (ret.second == false)
		throw DuplicatedDataBaseException();
}

void	BitcoinExchange::parseDate(std::string &str)
{
	int	year;
	int	month;
	int	day;

	if (str.find_first_not_of("0123456789-") != std::string::npos || str.find_first_of("-") != 4
		|| str.find_first_of("-", 5) != 7 || str.find_first_of("-", 8) != std::string::npos)
		throw InputErrorException();
	year = atoi(str.c_str());
	month = atoi(str.c_str() + 5);
	day = atoi(str.c_str() + 8);

	if (month < 1 || month > 12 || day < 1)
		throw InputErrorException();
	if (day > 31 && ((month < 8 && month % 2) || (month > 7 && month % 2 == 0)))
		throw InputErrorException();
	if (day > 30 && ((month < 8 && month % 2 == 0) || (month > 7 && month % 2)))
		throw InputErrorException();
	if (month == 2 && day > 28)
	{
		if (day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
			return ;
		throw InputErrorException();
	}
}

void	BitcoinExchange::readInput(void)
{
	std::string	tmp;

	while (std::getline(this->_input_file, tmp))
	{
		try
		{
			this->parseInputLine(tmp);
		}
		catch(const BitcoinExchange::InputErrorException& e)
		{
			std::cout << e.what() << tmp << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

	}
}

void	BitcoinExchange::parseInputLine(std::string &str)
{
	std::string								key;
	float									nb;
	std::map<std::string, float>::iterator	it;

	if (str == "date | value")
		return ;
	if (str.size() < 14 || str.find(" | ") != 10 || str.find_first_not_of("-0123456789| .") != std::string::npos || str.find_first_of("0123456789", 13) > 14)
		throw InputErrorException();
	key = str.substr(0, 10);
	this->parseDate(key);
	nb = std::atof(str.c_str() + 12);
	if (nb < 0)
		throw NegativeNumberException();
	if (nb >= 1000.0)
		throw TooLargeNumberException();
	it = this->_data.find(key);
	if ((*it).first == key)
		std::cout << key << " => " << nb << " = " << nb * (*it).second << std::endl;
	else
	{
		it = this->_data.lower_bound(key);
		if (--it == this->_data.end())
			throw DateNotFoundException();
		std::cout << key << " => " << nb << " = " << nb * (*it).second << std::endl;
	}
}

const char	*BitcoinExchange::NoDataBaseException::what() const throw()
{
	return "Error: could not open csv file.";
}

const char	*BitcoinExchange::CorrompedDataBaseException::what() const throw()
{
	return "Error: the data in the csv file seems not compatible with the requeriments.";
}

const char	*BitcoinExchange::NoInputException::what() const throw()
{
	return "Error: could not open file.";
}

const char	*BitcoinExchange::InputErrorException::what() const throw()
{
	return "Error: bad input => ";
}

const char	*BitcoinExchange::DuplicatedDataBaseException::what() const throw()
{
	return "Error: there is a duplicated data in the csv file";
}

const char	*BitcoinExchange::NegativeNumberException::what() const throw()
{
	return "Error: not a positive number.";
}

const char	*BitcoinExchange::TooLargeNumberException::what() const throw()
{
	return "Error: too large a number.";
}

const char	*BitcoinExchange::DateNotFoundException::what() const throw()
{
	return "Error: date not found in the database";
}
