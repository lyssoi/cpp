#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(WrongAnimal const &temp);
		WrongAnimal &operator=(WrongAnimal const &temp);
		const std::string& getType(void) const;
		void makeSound(void) const;
};

#endif