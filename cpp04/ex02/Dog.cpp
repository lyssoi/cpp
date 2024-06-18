#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor is called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destrucotr is called" << std::endl;
}

Dog::Dog(Dog const &temp):Animal(temp)
{
	*this = temp;
	std::cout << "Dog copy constructor is called " << std::endl;
}

Dog& Dog::operator=(Dog const &temp)
{
	if (this == &temp)
		return (*this);
	Animal::operator=(temp);
	brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		brain[i] = temp.brain[i];
	}
	std::cout << "Dog assignment operator is called " << std::endl;
	return (*this);
}

void  Dog::makeSound(void) const
{
	std::cout << "dooooooooooooog" << std::endl;
}