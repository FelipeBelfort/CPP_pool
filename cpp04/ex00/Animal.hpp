#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string	type;

public:
	Animal(void);
	~Animal();
	Animal(const Animal &copy);
	Animal	&operator=(const Animal &copy);

	void	makeSound(void);
};

#endif
