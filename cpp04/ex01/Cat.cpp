#include "Cat.hpp"

Cat::Cat(const std::string &name)
{
	this->_type = name;
	std::cout << "Cat created" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	this->_type = copy._type;
	std::cout << "Cat created by copy" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat	&Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		this->brain = copy.brain;
	}
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Shut up slave!" << std::endl;
}