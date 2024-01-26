#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_energy = 50;
	this->_life = 100;
	this->_damage = 20;
	std::cout << "ScavTrap " << name << " created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destroyed." << std::endl;
}

ScavTrap::ScavTrap(const ClapTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap " << this->_name << " created by copy." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!this->_energy)
	{
		std::cout << "ScavTrap " << this->_name;
		if (!this->_life)
			std::cout << " is dead." << std::endl;
		else
			std::cout << " has no energy to do any action." << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode." << std::endl;
}