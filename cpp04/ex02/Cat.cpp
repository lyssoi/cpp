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

Cat::Cat(Cat const &temp):Animal(temp), brain(0)
{
	*this = temp;
	std::cout << "Cat copy constructor is called " << std::endl;
}

Cat& Cat::operator=(Cat const &temp)
{
	if (this == &temp)
		return (*this);
	Animal::operator=(temp);
	if (this->brain != 0)
		delete this->brain;
	this->brain = new Brain(*(temp.brain));
	std::cout << "Cat assignment operator is called " << std::endl;
	return (*this);
}

void  Cat::makeSound(void) const
{
	std::cout << "caaaaaaaaaaaatt" << std::endl;
}

void Cat::setBrainIdea(int idx, std::string idea)
{
	brain->setIdea(idx, idea);
}

const std::string Cat::getBrainIdea(int idx)
{
	return brain->getIdea(idx);
}

const Brain *Cat::getBrain()
{
	return (this->brain);
}