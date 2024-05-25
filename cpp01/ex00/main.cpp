# include "Zombie.h"

int main()
{
	Zombie *zo1 = newZombie("sol");
	zo1->announce();
	randomChump("sol2");
	delete zo1;
	return (0);
}