#include "Intern.hpp"

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

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	formNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	AForm	*formConstruct[] =
	{new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return formConstruct[i];

		}
	}
	std::cout << "Intern couldn't find this form." << std::endl;
	return NULL;
}

AForm	*Intern::alsoMakeForm(std::string name, std::string target)
{
	std::string	formNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	AForm	*formConstruct[] =
	{new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return formConstruct[i];

		}
	}
	std::cout << "Intern couldn't find this form." << std::endl;
	return NULL;
}
