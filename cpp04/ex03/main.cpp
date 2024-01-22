#include "Ice.hpp"
#include "Character.hpp"

int	main(void)
{
	ICharacter	*character1 = new Character("Ze");
	ICharacter	*character2 = new Character("Bob");

	character1->equip(new Ice());
	character1->equip(new Ice());

	character1->use(0, *character2);
	character1->use(1, *character2);
	character1->use(4, *character2);
	character1->use(2, *character2);

	delete character1;
	delete character2;

	return 0;
}
