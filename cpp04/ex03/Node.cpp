#include "Node.hpp"

Node::Node(AMateria *data) : _data(data), _next(NULL)
{}

Node::~Node(void)
{
	if (this->_data)
		delete this->_data;
}

Node::Node(const Node &copy) : _data(NULL), _next(NULL)
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
	this->_next = node;
}

Node	*Node::getNext(void)
{
	return this->_next;
}
