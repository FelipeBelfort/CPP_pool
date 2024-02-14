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



// 2012-01-11 | a
