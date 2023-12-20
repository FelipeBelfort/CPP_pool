#include "Contact.hpp"

Contact::Contact()
{
	this->set_saved(0);
}

Contact::~Contact()
{
}

/**
 * @brief Function to set all attributes.
 *  It receives a table of strings to be used in order.
 *
 * @param std::string data[]
 */
void	Contact::hydrate(std::string *data)
{
	this->set_f_name(data[0]);
	this->set_l_name(data[1]);
	this->set_n_name(data[2]);
	this->set_phone(data[3]);
	this->set_secret(data[4]);
	this->set_saved(1);
	std::cout << this->get_f_name() << "'s contact saved" << std::endl;
}

int		Contact::get_saved()
{
	return this->_saved;
}

std::string	Contact::get_f_name()
{
	return this->_f_name;
}

std::string	Contact::get_l_name()
{
	return this->_l_name;
}

std::string	Contact::get_n_name()
{
	return this->_n_name;
}

std::string	Contact::get_phone()
{
	return this->_phone;
}

std::string	Contact::get_secret()
{
	return this->_secret;
}

void	Contact::set_saved(int status)
{
	this->_saved = status;
}

void	Contact::set_f_name(std::string info)
{
	this->_f_name = info;
}

void	Contact::set_l_name(std::string info)
{
	this->_l_name = info;
}

void	Contact::set_n_name(std::string info)
{
	this->_n_name = info;
}

void	Contact::set_phone(std::string info)
{
	this->_phone = info;
}

void	Contact::set_secret(std::string info)
{
	this->_secret = info;
}

