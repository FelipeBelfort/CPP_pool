#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int main( void )
{
    std::cout << "\n\n--------------- Animal ---------------\n" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Meta Type: " << meta->getType() << " " << std::endl;
    std::cout << "J Type: " << j->getType() << " " << std::endl;
    std::cout << "I Type: " << i->getType() << " " << std::endl;
    meta->makeSound();
    j->makeSound();
    i->makeSound();

    delete  meta;
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

    return 0;
}
