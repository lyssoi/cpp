#include "FragTrap.hpp"

int main()
{
	{
		std::cout << "==== 기본 생성자 && 네임 생성자 ====" << std::endl << std::endl;
		FragTrap frag1;
		FragTrap frag2("frag2");

		frag1.attack("frag2");
		frag2.takeDamage(30);
		frag1.beRepaired(5);
		frag1.highFivesGuys();

		frag2.attack("frag1");
		frag1.takeDamage(30);
		frag2.beRepaired(5);
		frag2.highFivesGuys();
	}
	std::cout << std::endl;
	{
		std::cout << "==== 복사 생성자 && 네임 생성자 ====" << std::endl << std::endl;
		FragTrap frag1("frag1");
		FragTrap frag2(frag1);

		frag1.attack("frag2");
		frag2.takeDamage(30);
		frag1.beRepaired(5);
		frag1.highFivesGuys();

		frag2.attack("frag1");
		frag1.takeDamage(30);
		frag2.beRepaired(5);
		frag2.highFivesGuys();
	}
	std::cout << std::endl;
	{
		std::cout << "==== 할당 연산자 && 네임 생성자 ====" << std::endl << std::endl;
		
		FragTrap frag1("frag1");
		FragTrap frag2;

		frag2 = frag1;

		frag1.attack("frag2");
		frag2.takeDamage(30);
		frag1.beRepaired(5);
		frag1.highFivesGuys();

		frag2.attack("frag1");
		frag1.takeDamage(30);
		frag2.beRepaired(5);
		frag2.highFivesGuys();
	}
	return (0);
}