#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap(FragTrap const &temp);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap&operator=(FragTrap const &temp);
		void highFivesGuys();
};

#endif