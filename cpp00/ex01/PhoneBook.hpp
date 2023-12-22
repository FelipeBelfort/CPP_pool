#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include <string.h>
# include <sstream>

# define MAX_COUNT 8
# define MAX_LENGTH 10

# define COLOR_OK "\e[32m"
# define COLOR_ATENTION "\e[93m"
# define COLOR_NOK "\e[31m"
# define COLOR_BASE "\e[0m"
# define COLOR_FUN "\e[96m"

class PhoneBook
{
	private:
		Contact	_contacts[MAX_COUNT];

		void	show_field(std::string str);
		void	show_row(int i);
		void	show_instructions(void);
		int		peek_id(int i);
		int		isvalid_id(std::string str, int i);
		void	deal_eof(void);
	public:
		PhoneBook();
		~PhoneBook();
		int		add_contact(int id);
		void	search_contact();
};

#endif

