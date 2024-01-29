#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{

private:
public:
	Intern(void);
	~Intern(void);
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);

	AForm	*makeForm(std::string name, std::string target);
	static AForm	*alsoMakeForm(std::string name, std::string target);
};

#endif
