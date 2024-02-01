#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"
# include "Node.hpp"


class Floor
{
private:
	static Node	*node;
public:
	Floor(void);
	~Floor(void);
	Floor(const Floor &copy);
	Floor	&operator=(const Floor &copy);

	static void	collect(AMateria *garbage);
	static void	cleanAll(void);
};


#endif
