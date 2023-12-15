#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Hello!!!\nWelcome to your ultra modern Phone book that does not save contacts." << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Good Bye!" << std::endl;
}

void	PhoneBook::add_contact(int id)
{
	std::string	output[5] = {"First Name: ", "Last Name: ", "Nickame: ", "Phone Number: ", "Darkest secret: "};
	std::string	input[5];

	for (int i = 0; i < 5; i++)
	{
		std::cout << output[i];
		std::getline(std::cin, input[i]);
		while (input[i].empty())
		{
			std::cout << "A contact can’t have empty fields." << std::endl << "Try again >> ";
			std::getline(std::cin, input[i]);
			if (!std::cin)
					return ;
		}
	}

	this->_contacts[id].hydrate(input);
}

void	PhoneBook::show_field(std::string str)
{
	std::cout << '|' << std::setw(10);
	if (str.length() > 10)
		std::cout << str.substr(0,8) << ".";
	else
		std::cout << str;
}

void	PhoneBook::show_row(int i)
{
		std::cout << '|' << std::setw(10) << i;
		show_field(this->_contacts[i].get_f_name());
		show_field(this->_contacts[i].get_n_name());
		show_field(this->_contacts[i].get_l_name());
		std::cout << '|' << std::endl;
}

void	PhoneBook::search_contact()
{
	int			i = -1;
	std::string	str_tmp;


	std::cout << std::setfill('|') << std::setw(45) << '|' << std::endl;

	std::cout <<  std::setfill(' ');
	// std::cout << '|' << std::setw(10);
	while (this->_contacts[++i].get_saved())
		this->show_row(i);

	// if (this->_contacts[i].get_f_name().length() > 10)
	// 	std::cout << this->_contacts[i].get_f_name().substr(0,8) << ".";
	// else
	// 	std::cout << this->_contacts[i].get_f_name();

	// std::cout << '|' << std::setw(10) << this->_contacts[i].get_l_name();
	// std::cout << '|' << std::setw(10) << this->_contacts[i].get_n_name();
	std::cout << std::setfill('|') << std::setw(45) << '|' << std::endl;

	std::cin >> i;
	std::cout << i << std::endl;

	// for (int i = 0; i < 8; i++)
	// {
	// 	if (this->_contacts[i].get_saved())
	// 		std::cout << this->_contacts[i].get_f_name() << "\n" << this->_contacts[i].get_l_name() << "\n"
	// 		<< this->_contacts[i].get_n_name() << "\n" << this->_contacts[i].get_phone() << "\n" << this->_contacts[i].get_secret() << "\n";

	// }
}
