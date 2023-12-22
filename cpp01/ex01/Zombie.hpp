#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie();
	void	set_name(std::string name);
	void	announce(void);
};

#endif