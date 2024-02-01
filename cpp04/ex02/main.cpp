#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

#ifndef N
# define N 4
#endif

int main( void )
{
{
    std::cout << "\n\n--------------- Animal ---------------\n" << std::endl;

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << "J Type: " << j->getType() << " " << std::endl;
    std::cout << "I Type: " << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();

    delete  j;
    delete  i;

    std::cout << "\n\n------------- Wrong Animal -------------\n" << std::endl;

    const WrongAnimal *wrong = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();
    const WrongCat *wrongCat2 = new WrongCat();

    std::cout << "Wrong Type: " << wrong->getType() << " " << std::endl;
    std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
    std::cout << "WrongCat2 Type: " << wrongCat2->getType() << " " << std::endl;
    wrong->makeSound();
    wrongCat->makeSound();
    wrongCat2->makeSound();

    delete  wrong;
    delete  wrongCat;
    delete  wrongCat2;
}

{
    AAnimal *list[N];
    // AAnimal tmp1;
    // AAnimal *tmp2 = new AAnimal();
    Dog basic;
{
    Dog tmp = basic;
}

std::cout << "\n\n------------------------------\n" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << "Creating Animal " << i << ":" << std::endl;
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
}
    return 0;
}
