#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include <string.h>
# include <sstream>

class PhoneBook
{
	private:
		Contact	_contacts[8];

		void	show_field(std::string str);
		void	show_row(int i);
		void	show_instructions(void);
		int		peek_id(int i);
		int		isvalid_id(std::string str, int i);
		void	deal_eof(void);
	public:
		PhoneBook();
		~PhoneBook();
		int	add_contact(int id);
		void	search_contact();
};

#endif

