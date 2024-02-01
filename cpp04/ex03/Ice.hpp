#ifndef ICE_HPP
# define ICE_HPP

// #pragma once

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &copy);
		~Ice(void);
		Ice	&operator=(const Ice &copy);

		Ice* clone(void) const;
		void use(ICharacter& target);
};

#endif
