#include "Ice.hpp"
// #include "AMateria.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::~Ice(void)
{
}

Ice::Ice(const Ice &copy) : AMateria(copy.getType())
{
}

Ice &Ice::operator=(const Ice &copy)
{
	(void) copy;
	return *this;
}

Ice* Ice::clone(void) const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
