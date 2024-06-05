#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	name = "Frag";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;

	std::cout << "FragTrap " << name << " default constructor is called" << std::endl;
};

FragTrap::FragTrap(FragTrap const &temp):ClapTrap(temp)
{
	std::cout << "FragTrap " << name << "  copy constructor is called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructor is called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &temp)
{
	ClapTrap::operator=(temp);

	std::cout << "FragTrap " << name << " assignment operator is called " << std::endl;

	return *this;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " name constructor is called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " highfives guys" << std::endl;
}
