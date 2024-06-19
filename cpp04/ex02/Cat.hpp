#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		~Cat();
		Cat(Cat const &temp);
		Cat &operator=(Cat const &temp);
		void makeSound(void) const;
		void setBrainIdea(int idx, std::string idea);
		const std::string getBrainIdea(int idx);
		const Brain *getBrain();
};
#endif