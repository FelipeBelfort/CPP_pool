#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::~AMateria(void)
{
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

std::string const & AMateria::getType(void) const
{
	return this->_type;
}
