#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "Animal created" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destroyed" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	*this = copy;
	std::cout << "Animal created by copy" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

// void	AAnimal::makeSound(void) const
// {
// 	std::cout << "An Animal sound" << std::endl;
// }

std::string	AAnimal::getType(void) const
{
	return this->_type;
}