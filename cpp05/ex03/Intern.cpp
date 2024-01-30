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

AForm	*Intern::factory(int i, std::string target)
{
	switch (i)
	{
	case 0:
		return new PresidentialPardonForm(target);
	case 1:
		return new RobotomyRequestForm(target);
	case 2:
		return new ShrubberyCreationForm(target);
	default:
		return NULL;
	}
}

// AForm	*Intern::makeForm(std::string name, std::string target)
// {
// 	std::string	formNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

// 	AForm	*formConstruct[] =
// 	{new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};

// 	for (int i = 0; i < 3; i++)
// 	{
// 		if (formNames[i] == name)
// 		{
// 			std::cout << "Intern creates " << name << std::endl;
// 			return formConstruct[i];

// 		}
// 	}
// 	std::cout << "Intern couldn't find this form." << std::endl;
// 	return NULL;
// }

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	formNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return factory(i, target);

		}
	}
	std::cout << "Intern couldn't find this form." << std::endl;
	return NULL;
}

AForm	*Intern::alsoMakeForm(std::string name, std::string target)
{
	std::string	formNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	// AForm	*formConstruct[] =
	// {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return factory(i, target);

		}
	}
	std::cout << "Intern couldn't find this form." << std::endl;
	return NULL;
}

// AForm	*Intern::alsoMakeForm(std::string name, std::string target)
// {
// 	std::string	formNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

// 	AForm	*formConstruct[] =
// 	{new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};

// 	for (int i = 0; i < 3; i++)
// 	{
// 		if (formNames[i] == name)
// 		{
// 			std::cout << "Intern creates " << name << std::endl;
// 			return formConstruct[i];

// 		}
// 	}
// 	std::cout << "Intern couldn't find this form." << std::endl;
// 	return NULL;
// }
