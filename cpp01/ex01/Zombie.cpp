#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "A zombie was created." << std::endl;
}

Zombie::Zombie(std::string name)
{
	set_name(name);
	std::cout << this->_name << " created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " destroyed." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
