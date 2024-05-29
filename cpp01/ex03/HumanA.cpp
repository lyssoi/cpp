#include "HumanA.hpp"

<<<<<<< HEAD
HumanA::HumanA(std::string name, Weapon &weapon):name_(name),weapon_(weapon)
=======
HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon)
>>>>>>> origin
{
}

void HumanA::attack()
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}