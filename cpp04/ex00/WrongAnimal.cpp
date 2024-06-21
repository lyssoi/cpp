#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor is called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout  << "WrongAnimal default destrucotr is called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &temp)
{
	*this = temp;
	std::cout << "WrongAnimal copy constructor is called " << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &temp)
{
	if (this == &temp)
		return (*this);
	type = temp.getType();
	std::cout << "WrongAnimal assignment operator is called " << std::endl;
	return (*this);
}

const std::string& WrongAnimal::getType(void) const
{
	return type;
}

void  WrongAnimal::makeSound(void) const
{
	std::cout <<"WWWWWWRONGAniiiiiiimaaaaaal" << std::endl;
}