#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor is called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout  << "Cat destrucotr is called" << std::endl;
}

Cat::Cat(Cat const &temp):Animal(temp)
{
	brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		brain[i] = temp.brain[i];
	}
	std::cout << "Cat copy constructor is called " << std::endl;
}

Cat& Cat::operator=(Cat const &temp)
{
	Animal::operator=(temp);
	brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		brain[i] = temp.brain[i];
	}
	std::cout << "Cat assignment operator is called " << std::endl;
	return (*this);
}

void  Cat::makeSound(void) const
{
	std::cout << "caaaaaaaaaaaatt" << std::endl;
}