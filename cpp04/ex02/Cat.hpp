#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal
{
	private:
	Brain	*brain;

	public:
	Cat(const std::string &name = "Cat");
	~Cat(void);
	Cat(const Cat &copy);
	Cat	&operator=(const Cat &copy);

	void	makeSound(void) const;

};

#endif
