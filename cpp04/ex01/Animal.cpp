#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal created" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destroyed" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "Animal created by copy" << std::endl;
}

Animal	&Animal::operator=(const Animal &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

void	Animal::makeSound(void) const
{
	std::cout << "An animal sound" << std::endl;
}

std::string	Animal::getType(void) const
{
	return this->_type;
}