#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	type = "ice";
}

Ice::~Ice()
{
}

Ice::Ice(Ice const &temp) : AMateria(temp)
{
	*this = temp;
}

Ice &Ice::operator=(Ice const &temp)
{
	if (this == &temp)
		return (*this);
	this->type = temp.getType();
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice* Ice::clone() const
{
	return (new Ice());
}