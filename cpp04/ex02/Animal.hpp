#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal() = 0;
		Animal(Animal const &temp);
		Animal &operator=(Animal const &temp);
		const std::string& getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif