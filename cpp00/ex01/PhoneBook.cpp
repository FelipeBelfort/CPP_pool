#include "PhoneBook.hpp"

// It will just write a welcome message.
PhoneBook::PhoneBook()
{
	std::cout << COLOR_FUN << "Hello!!!\n" << COLOR_BASE << "Welcome to your ultra modern Phone book that does not save your contacts.";
	show_instructions();
}
// It will just write a farewell message.
PhoneBook::~PhoneBook()
{
	std::cout << COLOR_NOK << "Your data has been deleted." << COLOR_ATENTION << std::endl;
	std::cout << "Good Bye!" << COLOR_BASE << std::endl;
}

/**
 * @brief
 *
 * It will calls the prompt and waits for the contact's informations to be used.
 * The function don't accepts empty fields
 * In case of abandon it returns fail.
 * In case of a contact creation it returns succes.
 * @param id The ID of the contact to create
 * @return int 0 if it fails or 1 if it succeeds
 */
int	PhoneBook::add_contact(int id)
{
	std::string	output[5] = {"First Name: ", "Last Name: ", "Nickame: ", "Phone Number: ", "Darkest secret: "};
	std::string	input[5];

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
			std::cout << COLOR_NOK << "A contact can’t have empty fields." << std::endl << COLOR_ATENTION << "Try again >> " << COLOR_BASE;
			std::getline(std::cin, input[i]);
		}
	}
	std::cout << COLOR_OK;
	this->_contacts[id].hydrate(input);
	std::cout << COLOR_BASE;
	return (1);
}

/**
 * @brief
 * It will clear the signal of the std::cin and then put back an information in it so it's not empty.
 * Finally it will show some messages to explain to the user what happened.
 *
 */
void	PhoneBook::deal_eof(void)
{
	std::cin.clear();
	std::cin.putback('\n');
	std::cout << COLOR_NOK << "\nYou abandoned this action" << COLOR_BASE << std::endl;
	show_instructions();
}

/**
 * @brief
 * Shows a simple message to explain the rules of the PhoneBook to the user
 *
 */
void	PhoneBook::show_instructions(void)
{
	std::cout << std::endl << "Please type " << COLOR_OK << "ADD" << COLOR_BASE;
	std::cout << " and " << COLOR_FUN << "SEARCH" << COLOR_BASE;
	std::cout << " to handle your contacts or " << COLOR_NOK << "EXIT." << std::endl;
	std::cout << COLOR_BASE << "Any other input is discarded." << std::endl;

}

/**
 * @brief
 * Show the received information in a formatted way
 *
 * @param str The information of the field
 */
void	PhoneBook::show_field(std::string str)
{
	std::string	tmp;

	tmp = str.substr(0, MAX_LENGTH);
	std::cout << COLOR_FUN << '|' << COLOR_BASE << std::setw(MAX_LENGTH);
	if (str.length() > MAX_LENGTH)
		tmp.at(MAX_LENGTH - 1) = '.';
	std::cout << tmp;
}

/**
 * @brief
 * It prints a row with all the fields of information of a contact `i`
 *
 * @param i The ID of the contact to show
 */
void	PhoneBook::show_row(int i)
{
		std::cout << COLOR_FUN << '|' << COLOR_BASE << std::setw(MAX_LENGTH) << i;
		show_field(this->_contacts[i].get_f_name());
		show_field(this->_contacts[i].get_l_name());
		show_field(this->_contacts[i].get_n_name());
		std::cout << COLOR_FUN << '|' << COLOR_BASE << std::endl;
}

/**
 * @brief
 * Checks if it's a valid `INT` and if it's a valid ID to be called
 * @param str The input of the user
 * @param i The number of existent contacts
 * @return int -1 if it's not valid otherwise the ID number
 */
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

/**
 * @brief
 * Gets the user input in a loop until it's a valid ID
 *
 * @param i The number of existent contacts
 * @return int -1 if it's not valid otherwise the ID number
 */
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
		std::cout << COLOR_NOK << "Not a valid Index." << std::endl << COLOR_ATENTION << "Try again >> " << COLOR_BASE;
		std::getline(std::cin, input);
	}
	return (-1);

}

/**
 * @brief
 * It prints a table of contacts.
 * If there are no contact it will show a message to empower the user.
 * Then it'll waits for the user's input to know which contact to show further information.
 *
 */
void	PhoneBook::search_contact()
{
	int			i = -1;
	std::string	input;

	if (!this->_contacts[0].get_saved())
	{
		std::cout << COLOR_FUN << "Sorry, it seems you don't have any friends yet." << std::endl;
		std::cout << "\e[1;93m www.youtube.com/watch?v=6EEW-9NDM5k" << COLOR_BASE << std::endl;
		return ;
	}
	std::cout << COLOR_FUN << std::setfill('|');
	std::cout << std::setw(MAX_LENGTH + 1) << "Index" << std::setw(MAX_LENGTH + 1) << "First Name" << std::setw(MAX_LENGTH + 1) << "Last Name" << std::setw(MAX_LENGTH + 1) << "Nickname"  << '|' << std::endl;

	std::cout << COLOR_BASE << std::setfill(' ');
	while (this->_contacts[++i].get_saved() && i < MAX_COUNT)
		this->show_row(i);
	std::cout << COLOR_FUN << std::setfill('|') << std::setw(((MAX_LENGTH + 1) * 4) + 1) << '|' << COLOR_BASE << std::endl;
	i = peek_id(i);
	if (i < 0)
		return ;
	std::cout << std::endl;
	std::cout << COLOR_OK << "First Name: " << COLOR_BASE << this->_contacts[i].get_f_name() << std::endl;
	std::cout << COLOR_OK << "Last Name: " << COLOR_BASE << this->_contacts[i].get_l_name() << std::endl;
	std::cout << COLOR_OK << "Nickame: " << COLOR_BASE << this->_contacts[i].get_n_name() << std::endl;
	std::cout << COLOR_OK << "Phone Number: " << COLOR_BASE << this->_contacts[i].get_phone() << std::endl;
	std::cout << COLOR_OK << "Darkest Secret: " << COLOR_BASE << this->_contacts[i].get_secret() << std::endl;
	show_instructions();
}
