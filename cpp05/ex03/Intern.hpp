#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

# define N 3

class Intern
{

private:
	static std::string	_formNames[N];
public:
	Intern(void);
	~Intern(void);
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);

	AForm	*createForm(int i, std::string target);
	AForm	*makeForm(std::string name, std::string target);
};

#endif
