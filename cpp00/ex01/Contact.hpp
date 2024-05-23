# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nick_name_;
		std::string phone_number_;
		std::string darkset_secret_;
	public:
		void set_first_name(std::string first_name);
		void set_last_name(std::string last_name);
		void set_nick_name(std::string nick_name);
		void set_phone_number(std::string phone_number);
		void set_darkset_secret(std::string darkset_secret);
		std::string get_first_name(void);
		std::string get_last_name(void);
		std::string get_nick_name(void);
		std::string get_phone_number(void);
		std::string get_darkset_secret(void);
};

# endif