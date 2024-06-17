#include "Character.hpp"

Character::Character()
{
	name = "";
	idx = 0;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(Character const &temp)
{
	*this = temp;
}

Character::Character(std::string name)
{
	this->name = name;
	idx = 0;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character &Character::operator=(Character const &temp)
{
	if (this == &temp)
		return (*this);
	this->name = temp.name;
	this->idx = temp.idx;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (idx > 3)
	{
		return ;
	}
	inventory[idx] = m;
	idx++;
}

void Character::unequip(int idx)
{
	inventory[idx] = NULL; // 여기서 릭 관리를 어떻게 할 것인지 생각해야함
	// equip할 때 idx를 어떻게 체킹할것인지..? bool 배열을 두는 방법도 있고..
	//
}

void Character::use(int idx, ICharacter &target)
{
	//The use(int, ICharacter&) member function will have to use the Materia at the slot[idx], and pass the target parameter to the AMateria::use function.
	AMateria::use(target); // ??
}