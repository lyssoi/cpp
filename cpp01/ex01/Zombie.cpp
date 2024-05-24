#include "Zombie.hpp"


Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	name_ = name;
}

Zombie::~Zombie()
{
	std::cout << name_ << "is destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	name_ = name;
}