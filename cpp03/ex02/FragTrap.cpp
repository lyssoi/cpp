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

	std::cout << "FragTrap " << name << " operator(=) is called " << std::endl;

	return *this;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " name constructor is called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (hitPoints <= 0 || energyPoints == 0)
	{
		std::cout << "no points" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " highfives guys" << std::endl;
}
