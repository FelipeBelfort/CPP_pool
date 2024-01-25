#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_energy;
		unsigned int	_life;
		unsigned int	_damage;
	public:
		ClapTrap(std::string name = "NoName");
		~ClapTrap(void);
		ClapTrap(const ClapTrap &copy);
		ClapTrap	&operator=(const ClapTrap &copy);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif