#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int	N;
	std::cout << "Combien de zombies t'en veux? ";
	std::cin >> N;
	Zombie *horde = zombieHorde(N, "aNewZombie");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}