#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "Clap";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;

	std::cout << "ClapTrap " << name << " default constructor is called" << std::endl;
};

ClapTrap::ClapTrap(ClapTrap const &temp)
{
	name = temp.name;
	hitPoints = temp.hitPoints;
	energyPoints = temp.energyPoints;
	attackDamage = temp.attackDamage;
	std::cout << "ClapTrap " << name << " copy constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor is called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &temp)
{
	name = temp.name;
	hitPoints = temp.hitPoints;
	energyPoints = temp.energyPoints;
	attackDamage = temp.attackDamage;

	std::cout << "ClapTrap " << name << " operator(=) is called" << std::endl;

	return *this;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap " << name << " name constructor is called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "no points" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "no points" << std::endl;
		return ;
	}
	hitPoints-=amount;
	std::cout << "ClapTrap " << name << " is damaged " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0 || energyPoints == 0)
	{
		std::cout << "no points" << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints+=amount;
	std::cout << "ClapTrap " << name << " is repaired " << amount << std::endl;
}

