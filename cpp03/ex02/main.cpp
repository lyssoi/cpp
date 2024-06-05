#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav;
	ScavTrap scav2("scav2");
	ScavTrap scav_is_copied("scav_copy");
	ScavTrap scav_is_operated("scav_oper");
	ScavTrap scav_copy(scav_is_copied);
	ScavTrap scav_oper;
	scav_oper = scav_is_operated;

	scav.attack("scav2");
	scav.takeDamage(3);
	scav.beRepaired(5);
	scav2.attack("scav");
	scav2.takeDamage(3);
	scav2.beRepaired(5);
	scav2.guardGate();
	return (0);
}