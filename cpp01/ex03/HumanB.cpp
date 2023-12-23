#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_weapon = NULL;
	this->_name = name;
	std::cout << "HumanB " << name << " created" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB " << this->_name << " destroyed" << std::endl;
}

void	HumanB::attack(void)
{

	std::cout << this->_name << " attacks with his ";
	std::cout << (this->_weapon ? this->_weapon->getType() : "fist") << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
