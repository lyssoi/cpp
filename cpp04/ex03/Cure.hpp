# ifndef CURE_HPP
# define CURE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(Cure const &temp);
		Cure &operator=(Cure const &temp);
		Cure* clone() const;
		void use(Icharacter& target);
};
# endif