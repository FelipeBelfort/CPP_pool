#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define N 5

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
	Base	*lst[N];

	std::srand(std::time(NULL));
	for (int i = 0; i < N; i++)
	{
		lst[i] = generate();
		identify(lst[i]);
		identify(*lst[i]);
		delete lst[i];
	}

	return 0;
}
