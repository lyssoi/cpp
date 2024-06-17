#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	type = "cure";
}

Cure::~Cure()
{
}

Cure::Cure(Cure const &temp)
{
	*this = temp;
}

Cure &Cure::operator=(Cure const &temp)
{
	if (this == &temp)
		return ;
	this->type = temp.type;
}


Cure* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(Icharacter& target)
{
	std::cout << "* heals" << target.getName() << "’s wounds *" << std::endl;
}