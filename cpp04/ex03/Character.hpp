#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Floor.hpp"

class Character : public ICharacter
{
private:
	Floor		floor;
	std::string	_name;
	AMateria	*_materias[4];

public:
	Character(const std::string &name = "John Doe");
	~Character(void);
	Character(const Character &copy);
	Character	&operator=(const Character &copy);

	const std::string	&getName(void) const;
	void 				equip(AMateria* m);
	void 				unequip(int idx);
	void 				use(int idx, ICharacter& target);

};


#endif
