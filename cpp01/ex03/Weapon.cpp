#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string type)
{
	type_ = type;
}

void Weapon::setType(std::string type)
{
	type_ = type;
}

std::string Weapon::getType()
{
	return (type_);
}