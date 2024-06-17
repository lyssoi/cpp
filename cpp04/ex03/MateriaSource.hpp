#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource() {}
		MateriaSource(MateriaSource const &temp);
		MateriaSource &operator=(MateriaSource const &temp);
		~MateriaSource() {}
		void learnMateria(AMateria *);
		AMateria* createMateria(std::string const &type);
};
#endif