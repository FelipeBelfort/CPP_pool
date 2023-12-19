#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Hello!!!\nWelcome to your ultra modern Phone book that does not save contacts.";
	show_instructions();
}

PhoneBook::~PhoneBook()
{
	std::cout << "Good Bye!" << std::endl;
}

int	PhoneBook::add_contact(int id)
{
	std::string	output[5] = {"First Name: ", "Last Name: ", "Nickame: ", "Phone Number: ", "Darkest secret: "};
	std::string	input[5];
	std::string	test;

	for (int i = 0; i < 5; i++)
	{
		std::cout << output[i];
		std::getline(std::cin, input[i]);
		while (input[i].empty() || (input[i].find_first_not_of(" \t") >= input[i].length()))
		{
			if (!std::cin)
			{
				deal_eof();
				return (0);
			}
			std::cout << "A contact can’t have empty fields." << std::endl << "Try again >> ";
			std::getline(std::cin, input[i]);
		}
	}

	this->_contacts[id].hydrate(input);
	return (1);
}

void	PhoneBook::deal_eof(void)
{
	std::cin.clear();
	std::cin.ignore();
	std::cin.putback('\n');
	std::cout << "\nyou abandoned this action" << std::endl;
	show_instructions();
}

void	PhoneBook::show_instructions(void)
{
	std::cout << std::endl << "Please type ADD, SEARCH to handle your contacts or EXIT." << std::endl;
	std::cout << "Any other input is discarded." << std::endl;

}

void	PhoneBook::show_field(std::string str)
{
	std::string	tmp;

	tmp = str.substr(0, 10);
	std::cout << '|' << std::setw(10);
	if (str.length() > 10)
		tmp.at(9) = '.';
	std::cout << tmp;
}

void	PhoneBook::show_row(int i)
{
		std::cout << '|' << std::setw(10) << i;
		show_field(this->_contacts[i].get_f_name());
		show_field(this->_contacts[i].get_l_name());
		show_field(this->_contacts[i].get_n_name());
		std::cout << '|' << std::endl;
}

int	PhoneBook::isvalid_id(std::string str, int i)
{
	int	id;

	if (str.empty())
		return (-1);
	id = atoi(str.c_str());
	if (id > 0 && id < i)
		return (id);
	if (!id && ((str.find_first_not_of("0") >= str.length() || (str.find_first_not_of("0+-") >= str.length() && str.find_last_of("+-") == 0 && str.length() > 1))))
		return (id);
	return (-1);
}

int	PhoneBook::peek_id(int i)
{
	std::string	input;
	int			id;

	std::cout << "Choose an Index >> ";
	std::getline(std::cin, input);
	while (1)
	{
		if (!std::cin)
		{
			deal_eof();
			break ;
		}
		id = isvalid_id(input, i);
		if (id >= 0)
			return (id);
		std::cout << "Not a valid Index." << std::endl << "Try again >> ";
		std::getline(std::cin, input);
	}
	return (-1);

}

void	PhoneBook::search_contact()
{
	int			i = -1;
	std::string	input;

	if (!this->_contacts[0].get_saved())
	{
		std::cout << "Sorry, it seems you don't have any friends yet." << std::endl;
		std::cout << "www.youtube.com/watch?v=6EEW-9NDM5k" << std::endl;
		return ;
	}
	std::cout << std::setfill('|');
	std::cout << std::setw(11) << "Index" << std::setw(11) << "First Name" << std::setw(11) << "Last Name" << std::setw(11) << "Nickname"  << '|' << std::endl;

	std::cout <<  std::setfill(' ');
	while (this->_contacts[++i].get_saved() && i < 8)
		this->show_row(i);
	std::cout << std::setfill('|') << std::setw(45) << '|' << std::endl;
	i = peek_id(i);
	if (i < 0)
		return ;
	std::cout << std::endl;
	std::cout << "First Name: " << this->_contacts[i].get_f_name() << std::endl;
	std::cout << "Last Name: " << this->_contacts[i].get_l_name() << std::endl;
	std::cout << "Nickame: " << this->_contacts[i].get_n_name() << std::endl;
	std::cout << "Phone Number: " << this->_contacts[i].get_phone() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[i].get_secret() << std::endl;
	show_instructions();
}
