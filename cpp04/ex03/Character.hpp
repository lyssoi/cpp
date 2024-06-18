#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"
class Character : public ICharacter {
	private:
		std::string name;
		AMateria *inventory[4];
		AMateria *floor[4];
	public:
		Character();
		Character(Character const &temp);
		Character(std::string name);
		~Character();
		Character &operator=(Character const &temp);
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		void left(AMateria *m);
		void cleanFloor();
		void cleanInventory();
};
#endif