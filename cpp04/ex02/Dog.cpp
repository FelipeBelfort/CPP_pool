#include "Dog.hpp"

Dog::Dog(const std::string &name)
{
	this->_type = name;
	std::cout << "Dog created" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	this->_type = copy._type;
	std::cout << "Dog created by copy" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Dog	&Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		this->brain = copy.brain;
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "I love you!" << std::endl;
}