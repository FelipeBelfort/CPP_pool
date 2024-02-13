#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm::AForm("RobotomyRequestForm", 72, 45)
{
	*this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	this->setTarget(copy.getTarget());
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void		RobotomyRequestForm::setTarget(std::string newTarget)
{
	this->_target = newTarget;
}

void		RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	(void) executor;

	std::srand(time(0));
	std::cout << "Makes some drilling noises..." << std::endl;
	if (std::rand() <= RAND_MAX / 2)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}
