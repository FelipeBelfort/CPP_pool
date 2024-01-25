#ifndef NODE_HPP
# define NODE_HPP

# include "AMateria.hpp"

class Node
{
private:
	AMateria	*_data;
	Node		*_next;

public:
	Node(AMateria *data);
	~Node(void);
	Node(const Node &copy);
	Node	&operator=(const Node &copy);

	void	push(Node *node);
	Node	*getNext(void);

};

#endif
