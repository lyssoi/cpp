# ifndef ICE_HPP
# define ICE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(Ice const &temp);
		Ice &operator=(Ice const &temp);
		Ice* clone() const;
		void use(Icharacter& target);
};
# endif