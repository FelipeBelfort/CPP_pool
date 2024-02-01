#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_materias[4];
public:
	MateriaSource(void);
	~MateriaSource(void);
	MateriaSource(const MateriaSource &copy);
	MateriaSource &operator=(const MateriaSource &copy);

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);
};

#endif
