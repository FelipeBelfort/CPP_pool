#include "Intern.hpp"

std::string	Intern::_formNames[N] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void) copy;
	return *this;
}

AForm	*Intern::createForm(int i, std::string target)
{
	switch (i)
	{
	case 0:
		return (new PresidentialPardonForm(target));
	case 1:
		return (new RobotomyRequestForm(target));
	case 2:
		return (new ShrubberyCreationForm(target));
	default:
		return NULL;
	}
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	
}
