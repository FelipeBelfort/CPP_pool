#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap01("clap01");
	ClapTrap clap02("clap02");
	ClapTrap clap03("clap03");
	ClapTrap clap04;

	clap04.takeDamage(10);
	clap01.attack("segfault");
	clap01.attack("compiler error");
	clap01.attack("leaks");
	clap01.takeDamage(5);
	clap02.takeDamage(9);
	clap02.takeDamage(10);
	clap02.attack("");
	clap03.beRepaired(10);
	clap03.takeDamage(19);
	return 0;
}