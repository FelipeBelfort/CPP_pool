#include "Floor.hpp"

Node	*Floor::node = NULL;

Floor::Floor(void)
{}

Floor::~Floor(void)
{}

Floor::Floor(const Floor &copy)
{
	*this = copy;
}

Floor	&Floor::operator=(const Floor &copy)
{
	(void) copy;
	return *this;
}

void	Floor::collect(AMateria *garbage)
{
	Node	*tmp = new Node(garbage);
	Node	*last = Floor::node;

	if (!Floor::node)
		Floor::node = tmp;
	else
	{
		while (last->getNext())
			last = last->getNext();
		last->push(tmp);
	}
}

void	Floor::cleanAll(void)
{
	Node	*curr = Floor::node;

	while (Floor::node)
	{
		curr = Floor::node;
		Floor::node = Floor::node->getNext();
		delete curr;
	}
}
