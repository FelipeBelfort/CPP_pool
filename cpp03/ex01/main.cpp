#include "ScavTrap.hpp"

int main()
{
	ClapTrap test01("Test01");
	ScavTrap test02("Test02");
	ScavTrap test03("Test03");
	ScavTrap test04("Test04");
	ScavTrap test05("Test05");

	test01.attack("wind");
	test01.attack("fire");
	test01.attack("water");
	test01.takeDamage(5);
	test02.takeDamage(9);
	test02.takeDamage(10);
	test02.attack("earth");
	test03.beRepaired(10);
	test03.takeDamage(19);
	test04.attack("heart");
	test04.takeDamage(99);
	test04.beRepaired(50);
	test04.guardGate();
	test05.attack("Captain Planet");
	test05.takeDamage(99);
	test05.beRepaired(50);
}