#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"
class Character : public ICharacter {
	private:
		std::string name;
		AMateria *inventory[4]; //why... pointer로 선언해야하는거지?
		int idx;
	public:
		Character();
		Character(Character const &temp);
		Character(std::string name);
		~Character(){}
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};
#endif