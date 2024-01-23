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

	void	collect(AMateria *garbage);
	void	cleanAll(void);
};


#endif
