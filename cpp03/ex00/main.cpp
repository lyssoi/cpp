#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap;
	ClapTrap clap2("clap2");

	clap.attack("clap2");
	clap.takeDamage(3);
	clap.beRepaired(5);
	clap2.attack("clap2");
	clap2.takeDamage(3);
	clap2.beRepaired(5);
	return (0);
}