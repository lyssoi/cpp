#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << " Dog default constructor is called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destrucotr is called" << std::endl;
}

Dog::Dog(Dog const &temp):Animal(temp)
{
	std::cout << "Dog copy constructor is called " << std::endl;
}

Dog& Dog::operator=(Dog const &temp)
{
	Animal::operator=(temp);
	std::cout << "Dog assignment operator is called " << std::endl;
	return (*this);
}

void  Dog::makeSound(void) const
{
	std::cout << "dooooooooooooog" << std::endl;
}