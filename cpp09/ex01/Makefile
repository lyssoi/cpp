NAME = RPN
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -MMD -MP -fsanitize=address -std=c++98
SRC = main.cpp\
	BitcoinExchange.cpp

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