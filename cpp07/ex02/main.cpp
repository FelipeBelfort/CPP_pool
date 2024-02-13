#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    // const Array<int> numbers(MAX_VAL);

    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // std::cout << numbers[7] << std::endl;
    // numbers[7] = 12;
    // std::cout << numbers[7] << std::endl;
    //SCOPE
    {
        Array<int> tmp;
        tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	for (size_t i = 0; i < 15; i++)
	{
		std::cout << numbers[i] << std::endl;
	}

    delete [] mirror;//
    return 0;
}
