#include "Character.hpp"

Character::Character()
{
	name = "";
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
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
		inventory[i] = temp.inventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	cleanFloor();
	cleanInventory();
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4 || inventory[idx] == NULL)
		return ;
	left(inventory[idx]);
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 4 || inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}

void Character::left(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (floor[i] == NULL)
		{
			floor[i] = m;
			return ;
		}
	}
	cleanFloor();
	floor[0] = m;
}

void Character::cleanFloor()
{
	for (int i = 0; i < 4; i++)
	{
		if (floor[i] != NULL)
		{
			delete floor[i];
			floor[i] = NULL;
		}
	}
}

void Character::cleanInventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}