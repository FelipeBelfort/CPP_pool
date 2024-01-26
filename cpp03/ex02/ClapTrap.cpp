#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_energy = 10;
	this->_life = 10;
	this->_damage = 0;
	std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	this->_name = copy._name;
	this->_life = copy._life;
	this->_energy = copy._energy;
	this->_damage = copy._damage;
	std::cout << "ClapTrap " << this->_name << " created by copy." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_life = copy._life;
		this->_energy = copy._energy;
		this->_damage = copy._damage;
	}
	std::cout << "ClapTrap " << this->_name << " created by assignment." << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->_energy)
	{
		std::cout << "ClapTrap " << this->_name;
		if (!this->_life)
			std::cout << " is dead." << std::endl;
		else
			std::cout << " has no energy to do any action." << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy)
	{
		std::cout << "ClapTrap " << this->_name;
		if (!this->_life)
			std::cout << " is dead." << std::endl;
		else
			std::cout << " has no energy to do any action." << std::endl;
		return ;
	}
	this->_energy--;
	this->_life += amount;
	std::cout << "ClapTrap " << this->_name << " repaired " << amount << " and now has " << this->_life << " hit points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " took a damage of " << amount;
	if (this->_life <= amount)
	{
		this->_life = 0;
		this->_energy = 0;
		std::cout << ", causing his death." << std::endl;
		return ;
	}
	this->_life -= amount;
	std::cout << " and now has " << this->_life << " hit points!" << std::endl;

}
