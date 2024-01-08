#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(const ClapTrap &copy);

		void attack(const std::string& target);
		void	guardGate(void);
};

#endif