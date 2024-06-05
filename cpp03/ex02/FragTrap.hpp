#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap(FragTrap const &temp);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap&operator=(FragTrap const &temp);
		void attack(const std::string& target);
		void highFivesGuys();
};

#endif