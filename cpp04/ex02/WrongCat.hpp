#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
	WrongCat(const std::string &name = "WrongCat");
	~WrongCat(void);
	WrongCat(const WrongCat &copy);
	WrongCat	&operator=(const WrongCat &copy);

	void	makeSound(void) const;

};

#endif
