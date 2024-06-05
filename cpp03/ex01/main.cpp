#include "ScavTrap.hpp"

int main()
{
	{
		std::cout << "==== 기본 생성자 && 네임 생성자 ====" << std::endl;
		ScavTrap scav1;
		ScavTrap scav2("scav2");

		scav1.attack("scav2");
		scav1.takeDamage(3);
		scav1.beRepaired(5);
		scav1.guardGate();
		scav2.attack("scav1");
		scav2.takeDamage(3);
		scav2.beRepaired(5);
		scav2.guardGate();
	}
	std::cout << std::endl;
	{
		std::cout << "==== 복사 생성자 && 네임 생성자 ====" << std::endl;
		ScavTrap scav1("scav1");
		ScavTrap scav2(scav1);

		scav1.attack("scav2");
		scav1.takeDamage(3);
		scav1.beRepaired(5);
		scav1.guardGate();
		scav2.attack("scav1");
		scav2.takeDamage(3);
		scav2.beRepaired(5);
		scav2.guardGate();
	}
	std::cout << std::endl;
	{
		std::cout << "==== 할당 연산자 && 네임 생성자 ====" << std::endl;
		
		ScavTrap scav1("scav1");
		ScavTrap scav2;

		scav2 = scav1;

		scav1.attack("scav2");
		scav1.takeDamage(3);
		scav1.beRepaired(5);
		scav1.guardGate();
		scav2.attack("scav1");
		scav2.takeDamage(3);
		scav2.beRepaired(5);
		scav2.guardGate();
	}
	return (0);
}