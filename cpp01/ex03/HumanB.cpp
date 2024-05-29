#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	name_ = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}

void HumanB::attack()
{
	std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}