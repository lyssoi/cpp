# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string name_;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		void set_name(std::string name);
};

# endif