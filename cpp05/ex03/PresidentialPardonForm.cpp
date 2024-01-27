#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm::AForm("PresidentialPardonForm", 25, 5)
{
	*this = copy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	this->setTarget(copy.getTarget());
	return *this;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void		PresidentialPardonForm::setTarget(std::string newTarget)
{
	this->_target = newTarget;
}

void		PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	(void) executor;
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
