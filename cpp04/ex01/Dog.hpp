#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(Dog const &temp);
		Dog &operator=(Dog const &temp);
		void makeSound(void) const;
		const Brain *getBrain();
		void setBrain(std::string str);
		void printBrain() const;
};
#endif