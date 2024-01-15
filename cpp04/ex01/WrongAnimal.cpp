#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout << "WrongAnimal created by copy" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "The wrong animal sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return this->_type;
}