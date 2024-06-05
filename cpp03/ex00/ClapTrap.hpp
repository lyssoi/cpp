#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
	public:
		ClapTrap();
		ClapTrap(ClapTrap const &temp);
		virtual ~ClapTrap();
		ClapTrap&operator=(ClapTrap const &temp);
		ClapTrap(std::string name);
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif