#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		// std::string	type;
	public:
		Ice(void);
		Ice(const Ice &copy);
		~Ice(void);
		Ice	&operator=(const Ice &copy);

		// std::string const & getType(void) const;
		Ice* clone(void) const;
		void use(ICharacter& target);
};

#endif
