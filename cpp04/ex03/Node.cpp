#include "Node.hpp"

Node::Node(AMateria *data) : _data(data), next(NULL)
{}

Node::~Node(void)
{
	if (this->_data)
		delete this->_data;
}

Node::Node(const Node &copy) : _data(NULL), next(NULL)
{
	(void) copy;
}

Node	&Node::operator=(const Node &copy)
{
	(void) copy;
	return *this;
}

void	Node::push(Node *node)
{
	this->next = node;
}
