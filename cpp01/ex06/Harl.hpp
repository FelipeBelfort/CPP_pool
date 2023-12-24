#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{

typedef void	(Harl::*ptr_f)(void);

private:
	static std::string	_level[4];
	static ptr_f		_f[4];
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Harl(void);
	~Harl(void);
	void	complain(std::string level);

};

#endif
