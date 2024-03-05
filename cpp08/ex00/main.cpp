#include "easyfind.hpp"
#include <list>
#include <vector>

#define N 50

int main()
{
	std::list<int> mylist;
	std::vector<int> myvector;

	srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		mylist.push_back((rand() % 60));
		myvector.push_back((rand() % 60));
	}
	std::cout << "Test List ==> ";
	easyfind(mylist, 30);
	std::cout << "Test Vector ==> ";
	easyfind(myvector, 30);


	return 0;
}
