#include "Harl.hpp"

std::string Harl::_level[4] =
	{"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::ptr_f	Harl::_f[4] =
	{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = 0;

	while (i < 4 && level.compare(_level[i]))
		i++;
	switch (i)
	{
	case	0:
		(this->*_f[0])();
	case	1:
		(this->*_f[1])();
	case	2:
		(this->*_f[2])();
	case	3:
		(this->*_f[3])();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
