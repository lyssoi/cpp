# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <sstream>


enum {
	FIRSTNAME,
	LASTNAME,
	NICKNAME,
	PHONENUMBER,
	DARKSETSECRET
};


class PhoneBook
{
	private:
		int	idx_;
		int	num_;
		Contact contacts[8];
		void printPhoneBook();
		void printPhoneBookIdx(int idx);
		void printFormattedString(const std::string &input);
		int strHasNotPrint(std::string str);
		int strIsSpace(std::string str);
		std::string	getUserInput(int flag);
	public:
		void add();
		void search();
		PhoneBook();
};
# endif