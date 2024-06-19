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
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
	*this = temp;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &temp)
{
	if (this == &temp)
		return (*this);
	for (int i = 0; i <4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
		inventory[i] = temp.getInventory()[i]->clone();
	}
	return (*this);
}

AMateria * const *MateriaSource::getInventory() const
{
	return (this->inventory);
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
			std::cout << m->getType() << " learn materia " << std::endl;
			return ;
		}
	}
	std::cout << "materiasource inventory is full! clean first materiasource and learn materia" << std::endl;
	delete inventory[0];
	inventory[0] = 0;
	for (int i = 1; i < 4; i++)
	{
		inventory[i - 1] = inventory[i];
	}
	inventory[3] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	std::cout << "type is none! " << std::endl;
	return (NULL);
}