#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	private:
		Contact	_contacts[8];

		void	show_field(std::string str);
		void	show_row(int i);
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact(int id);
		void	search_contact();
};

#endif

