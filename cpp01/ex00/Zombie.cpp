#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	name_ = name;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << name_ << "is destroyed" << std::endl;
}