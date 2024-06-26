#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(Brain const &ref);
		Brain& operator=(Brain const temp);
		const std::string *getIdeas() const;
		void setIdeas(std::string str);
		void printIdeas() const;
};

#endif