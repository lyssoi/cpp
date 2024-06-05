# include "Zombie.h"

int main()
{
	Zombie *zo1 = newZombie("sungyoon");
	zo1->announce();
	randomChump("sungyoon2");
	delete zo1;
	return (0);
}