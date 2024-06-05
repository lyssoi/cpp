#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
class Cat : public Animal
{
	private:
		Brain *brain_;
	public:
		Cat();
		~Cat();
		Cat(Cat const &temp);
		Cat &operator=(Cat const &temp);
		void makeSound(void) const;
};
#endif