#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat default constructor is called" << std::endl;
}

Cat::~Cat()
{
	std::cout  << "Cat destrucotr is called" << std::endl;
}

Cat::Cat(Cat const &temp):Animal(temp)
{
	std::cout << "Cat copy constructor is called " << std::endl;
}

Cat& Cat::operator=(Cat const &temp)
{
	Animal::operator=(temp);
	std::cout << "Cat assignment operator is called " << std::endl;
	return (*this);
}

void  Cat::makeSound(void) const
{
	std::cout << "caaaaaaaaaaaatt" << std::endl;
}