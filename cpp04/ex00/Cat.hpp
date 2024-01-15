#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal
{
	public:
	Cat(const std::string &name = "Cat");
	~Cat(void);
	Cat(const Cat &copy);
	Cat	&operator=(const Cat &copy);

	void	makeSound(void) const;

};

#endif
