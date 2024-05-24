# include "Zombie.h"

int main()
{
	Zombie *arr = zombieHorde(10, "sol");

	for (int i = 0; i < 10; i++)
	{
		arr->announce();
	}
	return (0);
}