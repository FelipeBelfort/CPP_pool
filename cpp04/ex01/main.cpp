#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

#ifndef N
# define N 4
#endif

int main( void )
{
    Animal  *list[N];
    Dog basic;
{
    Dog tmp = basic;
}

std::cout << "\n\n------------------------------\n" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << "Creating animal " << i << ":" << std::endl;
        if (i < N / 2)
            list[i] = new Cat();
        else
            list[i] = new Dog();
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << "Deleting Animal " << i << ":" << std::endl;
        delete list[i];
    }
    std::cout << "\n\n------------------------------\n" << std::endl;
    return 0;
}