#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[100];
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 1)
		{
			animals[i] = new Dog();
		}
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 100; i++)
	{
		delete animals[i];
	}
	Cat cat1;
	Cat cat2(cat1);
	return 0;
	
}