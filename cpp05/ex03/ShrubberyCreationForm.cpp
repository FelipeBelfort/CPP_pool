#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm::AForm("ShrubberyCreationForm", 145, 137)
{
	*this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->setTarget(copy.getTarget());
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void		ShrubberyCreationForm::setTarget(std::string newTarget)
{
	this->_target = newTarget;
}

void		ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	(void) executor;

	std::ofstream	file;

	file.open((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
		throw OpeningFileException();
	file << 	"      ^         ^         ^\n"
				"     ^^^       ^^^       ^^^\n"
				"    ^^^^^     ^^^^^     ^^^^^\n"
				"   ^^^^^^^   ^^^^^^^   ^^^^^^^\n"
				"  ^^^^^^^^^ ^^^^^^^^^ ^^^^^^^^^\n"
				" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
				"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
				"      |||       |||       |||";
	file.close();
}

const char	*ShrubberyCreationForm::OpeningFileException::what() const throw()
{
	return "Error creating the output file.";
}
