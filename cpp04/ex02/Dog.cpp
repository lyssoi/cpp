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
	std::cout  << "Dog destrucotr is called" << std::endl;
}

Dog::Dog(Dog const &temp):Animal(temp), brain(NULL)
{
	*this = temp;
	std::cout << "Dog copy constructor is called " << std::endl;
}

Dog& Dog::operator=(Dog const &temp)
{
	if (this == &temp)
		return (*this);
	Animal::operator=(temp);
	if (this->brain != 0)
		delete this->brain;
	this->brain = new Brain(*(temp.brain));
	std::cout << "Dog assignment operator is called " << std::endl;
	return (*this);
}

void  Dog::makeSound(void) const
{
	std::cout << "Dooooooooooooog" << std::endl;
}

const Brain *Dog::getBrain()
{
	return (this->brain);
}


void Dog::setBrain(std::string str)
{
	this->brain->setIdeas(str);
}

void Dog::printBrain() const
{
	this->brain->printIdeas();
}