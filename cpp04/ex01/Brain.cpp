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
		ideas[i] = ref.ideas[i];
	}
	std::cout << "Brain copy constructor is called" << std::endl;
}

Brain& Brain::operator=(Brain const temp)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = temp.ideas[i];
	}
	std::cout << "Brain assignment constructor is called" << std::endl;
	return (*this);
}

const std::string *Brain::getBrain()
{
	return this->ideas;
}

void Brain::setIdea(int idx, std::string idea)
{
	if (idx < 0 || idx >= 100)
		return ;
	ideas[idx] = idea;
}

const std::string Brain::getIdea(int idx)
{
	if (idx < 0 || idx >= 100)
		return (0);
	return (ideas[idx]);
}