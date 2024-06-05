#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(ScavTrap const &temp);
		~ScavTrap();
		ScavTrap&operator=(ScavTrap const &temp);
		ScavTrap(std::string name);
		void attack(const std::string& target);
		void guardGate();
};

#endif