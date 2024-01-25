#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_energy = 100;
	this->_life = 100;
	this->_damage = 30;
	std::cout << "FragTrap " << name << " created." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destroyed." << std::endl;
}

FragTrap::FragTrap(const ClapTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap " << this->_name << " created by copy." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::string	input;

	getline(std::cin, input);
	if (!std::cin || input.empty())
		return ;
	std::cout << this->_name << " says: \tHIGH FIVE!" << std::endl;
}
