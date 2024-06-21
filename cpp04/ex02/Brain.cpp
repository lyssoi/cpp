#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "idea";
	}
	std::cout << "Brain default constructor is called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called" << std::endl;
}

Brain::Brain(Brain const &ref)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = ref.getIdeas()[i];
	}
	std::cout << "Brain copy constructor is called" << std::endl;
}

Brain& Brain::operator=(Brain const temp)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = temp.getIdeas()[i];
	}
	std::cout << "Brain assignment constructor is called" << std::endl;
	return (*this);
}

const std::string *Brain::getIdeas() const
{
	return this->ideas;
}

void Brain::setIdeas(std::string str)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = str;
	}
}

void Brain::printIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << i << this->ideas[i] << std::endl;
	}
}