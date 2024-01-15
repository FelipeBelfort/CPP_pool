#include "Cat.hpp"

Cat::Cat(const std::string &name)
{
	this->_type = name;
	std::cout << "Cat created" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout << "Cat created by copy" << std::endl;
}

Cat	&Cat::operator=(const Cat &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Shut up slave!" << std::endl;
}