#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];
			for (int j = 0; j < static_cast<int>(arg.length()); j++)
			{
				arg[j] = std::toupper(arg[j]);
			}
			std::cout << arg;
		}
		std::cout << std::endl;
	}
	return (0);
}