#include "Character.hpp"

Character::Character()
{
	name = "";
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = 0;
		floor[i] = 0;
	}
}

Character::Character(Character const &temp)
{
	*this = temp;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = 0;
		floor[i] = 0;
	}
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = 0;
		floor[i] = 0;
	}
}

Character &Character::operator=(Character const &temp)
{
	if (this == &temp)
		return (*this);
	this->name = temp.name;
	cleanInventory();
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = temp.getInventory()[i]->clone();
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

AMateria *const *Character::getInventory() const
{
	return (this->inventory);
}

void Character::equip(AMateria *m)
{
	if (m == 0)
	{
		std::cout << "Wrong skill!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == 0)
		{
			inventory[i] = m;
			std::cout << m->getType() << " has been equipped in the inventory. " << std::endl;
			return ;
		}
	}
	std::cout << m->getType() << " has not been equipped in the inventory because inventory is full. " << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4 || inventory[idx] == 0)
	{
		std::cout << "idx is wrong! " << std::endl;
		return ;
	}
	left(inventory[idx]);
	inventory[idx] = 0;
	std::cout << inventory[idx]->getType() << " has been unequipped" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 4 || inventory[idx] == 0)
		return ;
	inventory[idx]->use(target);
}

void Character::left(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (floor[i] == 0)
		{
			floor[i] = m;
			std::cout << m->getType() << " has been dropped on the floor" << std::endl;
			return ;
		}
	}
	cleanFloor();
	floor[0] = m;
	std::cout << m->getType() << " has been dropped on the floor" << std::endl;
}

void Character::cleanFloor()
{
	for (int i = 0; i < 4; i++)
	{
		if (floor[i] != 0)
		{
			delete floor[i];
			floor[i] = 0;
		}
	}
	std::cout << " The floor has been cleaned " << std::endl;
}

void Character::cleanInventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != 0)
		{
			delete inventory[i];
			inventory[i] = 0;
		}
	}
	std::cout << " The inventory has been cleaned " << std::endl;
}