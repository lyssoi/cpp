#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &temp)
{
	*this = temp;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &temp)
{
	if (this == &temp)
		return (*this);
	for (int i = 0; i <4; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
		}
		inventory[i] = temp.inventory[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
	delete inventory[0];
	inventory[0] = NULL;
	for (int i = 1; i < 4; i++)
	{
		inventory[i - 1] = inventory[i];
	}
	inventory[3] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i <4; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return (NULL);
}