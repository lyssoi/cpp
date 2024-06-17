# ifndef CURE_HPP
# define CURE_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"
class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(Cure const &temp);
		Cure &operator=(Cure const &temp);
		Cure* clone() const;
		void use(ICharacter& target);
};
# endif