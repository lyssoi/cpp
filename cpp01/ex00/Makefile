NAME = ex00
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98
SRC = main.cpp\
	Zombie.cpp\
	newZombie.cpp\
	randomChump.cpp

OBJ = $(SRC:.cpp=.o)

DEP = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CPP) $(CPPFLAGS) -o $@ $^

-include $(DEP)

clean:
	rm -rf  $(OBJ) $(DEP)

fclean:
	make clean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re