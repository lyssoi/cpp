#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::AMateria(AMateria const &temp)
{
	*this = temp;
}

AMateria& AMateria::operator=(AMateria const &temp)
{
	if (&temp == this)
		return (*this);
	this->type = temp.getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}