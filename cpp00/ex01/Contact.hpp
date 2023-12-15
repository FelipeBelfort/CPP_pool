#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		int			_saved;
		std::string	_f_name;
		std::string	_l_name;
		std::string	_n_name;
		std::string	_phone;
		std::string	_secret;

		void		set_f_name(std::string info);
		void		set_l_name(std::string info);
		void		set_n_name(std::string info);
		void		set_phone(std::string info);
		void		set_secret(std::string info);
		void		set_saved(int status);
		
	public:
		Contact();
		~Contact();
		void		hydrate(std::string data[]);
		int			get_saved();
		std::string	get_f_name();
		std::string	get_l_name();
		std::string	get_n_name();
		std::string	get_phone();
		std::string	get_secret();
};

#endif
