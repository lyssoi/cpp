#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor is called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout  << "WrongCat destrucotr is called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &temp):WrongAnimal(temp)
{
	std::cout << "WrongCat copy constructor is called " << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &temp)
{
	WrongAnimal::operator=(temp);
	std::cout << "WrongCat assignment operator is called " << std::endl;
	return (*this);
}

void  WrongCat::makeSound(void) const
{
	std::cout << "WWWWWWWRONGcaaaaaaaaaaaatt" << std::endl;
}