#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	type = "Dog";
	brain_ = new Brain();
	std::cout << " Dog default constructor is called" << std::endl;
}

Dog::~Dog()
{
	delete brain_;
	std::cout << "Dog destrucotr is called" << std::endl;
}

Dog::Dog(Dog const &temp):Animal(temp)
{
	brain_ = new Brain();
	for (int i = 0; i < 100; i++)
	{
		brain_[i] = temp.brain_[i];
	}
	std::cout << "Dog copy constructor is called " << std::endl;
}

Dog& Dog::operator=(Dog const &temp)
{
	Animal::operator=(temp);
	brain_ = new Brain();
	for (int i = 0; i < 100; i++)
	{
		brain_[i] = temp.brain_[i];
	}
	std::cout << "Dog assignment operator is called " << std::endl;
	return (*this);
}

void  Dog::makeSound(void) const
{
	std::cout << "dooooooooooooog" << std::endl;
}