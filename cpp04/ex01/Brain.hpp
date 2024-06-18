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
		void setIdea(int idx, std::string idea);
		const std::string getIdea(int idx);
		const std::string *getBrain();
};

#endif