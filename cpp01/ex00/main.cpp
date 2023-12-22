#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int main()
{
	Zombie zombie1("zombie");
	Zombie *zombie2 = newZombie("aNewZombie");
	zombie1.announce();
	zombie2->announce();
	randomChump("AnotherZombie");
	delete zombie2;
}