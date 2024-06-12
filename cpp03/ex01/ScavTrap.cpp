#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	name = "Scav";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;

	std::cout << "ScavTrap " << name << " default constructor is called" << std::endl;
};

ScavTrap::ScavTrap(ScavTrap const &temp) : ClapTrap(temp)
{
	std::cout << "ScavTrap " << name << " copy constructor is called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &temp)
{
	ClapTrap::operator=(temp);
	std::cout << "ScavTrap " << name  << " operator(=) is called" << std::endl;

	return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " name constructor is called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (hitPoints <= 0 || energyPoints == 0)
	{
		std::cout << "no points" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " gatekeeper mode on" << std::endl;
}
