#include "Contact.hpp"

void Contact::set_first_name(std::string first_name)
{
	first_name_ = first_name;
}
void Contact::set_last_name(std::string last_name)
{
	last_name_ = last_name;
}
void Contact::set_nick_name(std::string nick_name)
{
	nick_name_ = nick_name;
}
void Contact::set_phone_number(std::string darkset_secret)
{
	darkset_secret_ = darkset_secret;
}
void Contact::set_darkset_secret(std::string first_name)
{
	first_name_ = first_name;
}


std::string Contact::get_first_name(void)
{
	return (first_name_);
}
std::string Contact::get_last_name(void)
{
	return (last_name_);
}
std::string Contact::get_nick_name(void)
{
	return (nick_name_);
}
std::string Contact::get_phone_number(void)
{
	return (phone_number_);
}
std::string Contact::get_darkset_secret(void)
{
	return (darkset_secret_);
}