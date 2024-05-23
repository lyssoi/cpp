# include "PhoneBook.hpp"
# include "Contact.hpp"

int main()
{
	PhoneBook book;
	std::string cmd;

	while (!std::cin.eof())
	{
		std::cout << "command (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin,cmd);
		if (cmd == "ADD")
			book.add();
		if (cmd == "SEARCH")
			book.search();
		if (cmd == "EXIT")
			break;
	}
	return (0);
}