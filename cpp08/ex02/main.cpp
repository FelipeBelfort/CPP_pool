#include "MutantStack.hpp"
#include <iostream>

#define N 10

int main()
{
	std::cout << "Begin of the subject main" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "Begin of my main" << std::endl;
    MutantStack<int> mutantStack;

    for (int i = 1; i <= N; ++i) {
        mutantStack.push(i * 10);
    }

    std::cout << "Stack elements:" << std::endl;
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
		*it -= 5;
    }
    std::cout << std::endl;

    std::cout << "Stack elements (const):" << std::endl;
    for (MutantStack<int>::const_iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
		// *it += 5;
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
