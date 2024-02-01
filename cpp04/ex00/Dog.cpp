#include "Dog.hpp"

Dog::Dog(const std::string &name)
{
	this->_type = name;
	std::cout << "Dog created" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	*this = copy;
	std::cout << "Dog created by copy" << std::endl;
}

Dog	&Dog::operator=(const Dog &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "I love you!" << std::endl;
}