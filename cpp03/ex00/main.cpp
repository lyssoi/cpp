#include "ClapTrap.hpp"

int main()
{
	{
		std::cout << "==== 기본 생성자 && 네임 생성자 ====" << std::endl;
		ClapTrap clap1;
		ClapTrap clap2("clap2");

		clap1.attack("clap2");
		clap2.takeDamage(0);
		clap1.beRepaired(5);

		clap2.attack("clap1");
		clap1.takeDamage(0);
		clap2.beRepaired(5);
	}
		std::cout << std::endl;
	{
		std::cout << "==== 복사 생성자 && 네임 생성자 ====" << std::endl;
		ClapTrap clap1("clap1");
		ClapTrap clap2(clap1);

		clap1.attack("clap2");
		clap2.takeDamage(0);
		clap1.beRepaired(5);

		clap2.attack("clap1");
		clap1.takeDamage(0);
		clap2.beRepaired(5);
	}
		std::cout << std::endl;
	{
		std::cout << "==== 할당 연산자 && 네임 생성자 ====" << std::endl;
		
		ClapTrap clap1("clap1");
		ClapTrap clap2;

		clap2 = clap1;

		clap1.attack("clap2");
		clap2.takeDamage(0);
		clap1.beRepaired(5);
		clap2.attack("clap1");
		clap1.takeDamage(0);
		clap2.beRepaired(5);
	}
	return (0);
}