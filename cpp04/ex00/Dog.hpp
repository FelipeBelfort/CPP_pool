#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
	Dog(const std::string &name = "Dog");
	~Dog(void);
	Dog(const Dog &copy);
	Dog	&operator=(const Dog &copy);

	void	makeSound(void) const;

};

#endif
