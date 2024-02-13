#include "easyfind.hpp"

#define N 50

int main()
{
	std::vector<int> myvector;

	srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		myvector.push_back((rand() % 60));
	}

	easyfind(myvector, 30);


	return 0;
}
