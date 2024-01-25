#include "Character.hpp"

Character::Character(const std::string &name) : _name(name)
{
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i])
			delete this->_materias[i];
}

Character::Character(const Character &copy) : _name(copy.getName())
{
	for (int i = 0; i < 4; i++)
		if (copy._materias[i])
			this->_materias[i] = copy._materias[i]->clone();
}

Character	&Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		this->_name = copy.getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
			if (copy._materias[i])
				this->_materias[i] = copy._materias[i]->clone();
		}
	}
	return *this;
}

const std::string	&Character::getName(void) const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
		if (m == this->_materias[i])
			return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = m;
			return ;
		}
	}
	Floor::collect(m);
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_materias[idx])
	{
		Floor::collect(this->_materias[idx]);
		this->_materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
		if (this->_materias[idx])
			this->_materias[idx]->use(target);
}
