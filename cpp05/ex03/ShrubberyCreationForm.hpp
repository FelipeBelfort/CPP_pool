 #ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
public:
	ShrubberyCreationForm(std::string target = "HOME");
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);

	std::string	getTarget(void) const;
	void		setTarget(std::string newTarget);
	void		execute(const Bureaucrat &executor) const;

	class OpeningFileException : public std::exception
	{
	public:

		const char *what() const throw();
	};
};

#endif
