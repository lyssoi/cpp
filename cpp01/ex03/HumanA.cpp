#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	name_ = name;
	weapon_ = weapon;
}

void HumanA::attack()
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}