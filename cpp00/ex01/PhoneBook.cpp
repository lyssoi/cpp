#include "PhoneBook.hpp"
# define TRUE 1
# define FALSE 0


PhoneBook::PhoneBook()
{
	idx_ = 0;
	num_ = 0;
}

int PhoneBook::strIsSpace(std::string str)
{
	int i = 0;

	while (str[i] && isspace(str[i]))
		i++;
	if (i == static_cast<int>(str.length()))
	{
		return (TRUE);
	}
	return (FALSE);
}

int	PhoneBook::strHasNotPrint(std::string str)
{
	for (int i = 0; i < static_cast<int>(str.length()); i++)
	{
		if (!isprint(str[i]))
			return (TRUE);
	}
	return (FALSE);
}

std::string	PhoneBook::getUserInput(int flag)
{
	std::string input;
	std::string output;

	if (flag == FIRSTNAME)
		output = "firstname : ";
	else if (flag == LASTNAME)
		output = "lastname : ";
	else if (flag == NICKNAME)
		output = "nickname : ";
	else if (flag == PHONENUMBER)
		output = "phonenumber : ";
	else if (flag == DARKSETSECRET)
		output = "darksetsecret : ";
	while (!std::cin.eof() && (input == "" || PhoneBook::strIsSpace(input) || PhoneBook::strHasNotPrint(input)))
	{
		std::cout << output;
		std::getline(std::cin,input);
	}
	return (input);
}

void	PhoneBook::add()
{
	std::string input;

	if (idx_ > 7)
		idx_ = 0;
	input = getUserInput(FIRSTNAME);
	contacts[idx_ % 8].set_first_name(input);
	input = getUserInput(LASTNAME);
	contacts[idx_ % 8].set_last_name(input);
	input = getUserInput(NICKNAME);
	contacts[idx_ % 8].set_nick_name(input);
	input = getUserInput(PHONENUMBER);
	contacts[idx_ % 8].set_phone_number(input);
	input = getUserInput(DARKSETSECRET);
	contacts[idx_ % 8].set_last_name(input);
	idx_++;
	if (idx_ < 8)
		num_++;
}

void	PhoneBook::search()
{
	std::string s_idx;
	int idx;

	std::cout << " ------------------------------------------- " << std::endl;
	PhoneBook::printPhoneBook();

	while (!std::cin.eof() && s_idx.empty())
	{
		std::cout << "idx : ";
		std::getline(std::cin, s_idx);
		if (!s_idx.empty())
		{
			std::stringstream ss(s_idx);
			if (!(ss >> idx) || idx < 0 || idx >= num_)
			{
				std::cout << "The index doesn't exist" << std::endl;
				s_idx.clear();
			}
		}
	}
	printPhoneBookIdx(idx);
}


void	PhoneBook::printFormattedString(const std::string &input) {
	if (input.length() > 10) {
		std::cout << input.substr(0, 9) << ".";
	} else {
		std::cout << std::setw(10) << input;
	}
}

void	PhoneBook::printPhoneBookIdx(int idx)
{
	std::cout << "All about information " << idx << std::endl;
	std::cout << "firstname : " << contacts[idx].get_first_name() << std::endl;
	std::cout << "lastname : " << contacts[idx].get_last_name() << std::endl;
	std::cout << "nickname : " << contacts[idx].get_nick_name() << std::endl;
	std::cout << "phonenumber : " << contacts[idx].get_phone_number() << std::endl;
	std::cout << "darset_secret : " << contacts[idx].get_darkset_secret() << std::endl;
}

void	PhoneBook::printPhoneBook()
{
	std::cout << "|";
	printFormattedString("index");
	std::cout << "|";
	printFormattedString("first name");
	std::cout << "|";
	printFormattedString("last name");
	std::cout << "|";
	printFormattedString("nickname");
	std::cout << "|";
	std::cout << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	for (int i = 0; i < num_; i++)
	{
		std::stringstream ss;
		ss << i;
		std::cout << "|";
		printFormattedString(ss.str());
		std::cout << "|";
		printFormattedString(contacts[i].get_first_name());
		std::cout << "|";
		printFormattedString(contacts[i].get_last_name());
		std::cout << "|";
		printFormattedString(contacts[i].get_nick_name());
		std::cout << "|";
		std::cout << std::endl;
		std::cout << " ------------------------------------------- " << std::endl;
	}
}