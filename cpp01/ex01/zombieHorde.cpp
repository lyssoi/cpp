#include "Zombie.hpp"
#include <sstream>

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *hord = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << name << i;
		hord[i].set_name(ss.str());
	};
	return (hord);
}