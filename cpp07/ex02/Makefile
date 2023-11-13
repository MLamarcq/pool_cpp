NAME	= Iter
CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98
SRC		= main.cpp array.cpp
OBJ		= $(SRC:.cpp=.o)
DEP		= $(SRC:.cpp=.d)
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

.cpp.o:
	$(CC) $(FLAGS) -MMD -MP -o $@ -c $<

-include $(DEP)

.PHONY: all clean fclean re

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

