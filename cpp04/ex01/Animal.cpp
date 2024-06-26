#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::~Animal()
{
	std::cout  << "Animal default destrucotr is called" << std::endl;
}

Animal::Animal(Animal const &temp)
{
	*this = temp;
	std::cout << "Animal copy constructor is called " << std::endl;
}

Animal& Animal::operator=(Animal const &temp)
{
	if (this == &temp)
		return (*this);
	type = temp.getType();
	std::cout << "Animal assignment operator is called " << std::endl;
	return (*this);
}

const std::string& Animal::getType(void) const
{
	return type;
}

void  Animal::makeSound(void) const
{
	std::cout <<"Aniiiiiiimaaaaaaaaaaaaaaaal" << std::endl;
}