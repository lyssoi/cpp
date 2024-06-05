# include "Zombie.h"

int main()
{
	Zombie *arr = zombieHorde(10, "sungyoon");

	for (int i = 0; i < 10; i++)
	{
		arr[i].announce();
	}
	delete[] arr;
	return (0);
}