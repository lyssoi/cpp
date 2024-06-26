#include "Character.hpp"

Character::Character() : ICharacter()
{
	name = "";
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
		floor[i] = NULL;
	}
}

Character::Character(Character const &temp) : ICharacter(temp)
{
	*this = temp;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
		floor[i] = NULL;
	}
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
		floor[i] = NULL;
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
	if (m == NULL)
	{
		std::cout << "Wrong skill!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << m->getType() << " has been equipped in the inventory. " << std::endl;
			return ;
		}
	}
	std::cout << m->getType() << " has not been equipped in the inventory because inventory is full. " << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || inventory[idx] == NULL)
	{
		std::cout << "idx is wrong! " << std::endl;
		return ;
	}
	std::cout << inventory[idx]->getType() << " has been unequipped" << std::endl;
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
		if (floor[i] != NULL)
		{
			delete floor[i];
			floor[i] = NULL;
		}
	}
	std::cout << " The floor has been cleaned " << std::endl;
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
	std::cout << " The inventory has been cleaned " << std::endl;
}