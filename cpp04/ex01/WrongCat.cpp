#include "WrongCat.hpp"

WrongCat::WrongCat(const std::string &name)
{
	this->_type = name;
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
	std::cout << "WrongCat created by copy" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Shut up slave!" << std::endl;
}