NAME = ClapTrap
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp\
	ClapTrap.cpp\
	ScavTrap.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CPP) $(CPPFLAGS) -o $@ $^


clean:
	rm -rf  $(OBJ)

fclean:
	make clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re