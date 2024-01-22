#ifndef	AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria(std::string const & type);
	virtual ~AMateria(void);
	AMateria(const AMateria &copy);
	AMateria	&operator=(const AMateria &copy);

	std::string const & getType(void) const; //Returns the materia type
	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target) = 0;
};

#endif
