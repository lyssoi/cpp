#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(Dog const &temp);
		Dog &operator=(Dog const &temp);
		void makeSound(void) const;
};
#endif