#ifndef CURE_HPP
# define CURE_HPP

// #pragma once

# include "AMateria.hpp"

// class AMateria;

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &copy);
		~Cure(void);
		Cure	&operator=(const Cure &copy);

		Cure* clone(void) const;
		void use(ICharacter& target);
};

#endif

