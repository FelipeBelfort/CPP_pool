#include "Cure.hpp"
// #include "AMateria.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// this->_type = "cure";
	// std::cout << "test" << std::endl;
}

Cure::~Cure(void)
{
}

Cure::Cure(const Cure &copy) : AMateria(copy.getType())
{
}

Cure &Cure::operator=(const Cure &copy)
{
	(void) copy;
	return *this;
}

Cure* Cure::clone(void) const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
