SRC		=	main.cpp
OBJ		=	$(SRC:.cpp=.o)
NAME	=	identifier
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -MD -MP -std=c++98
DEPENDS :=	$(SRC:.cpp=.d)


.PHONY	:	all re clean fclean

all		:	$(NAME)

$(NAME)	:	$(OBJ) Makefile
			$(CC) $(OBJ) -o $(NAME)

%.o		:	%.cpp
			$(CC) $(CFLAGS) -c $< -o ${<:.cpp=.o}

clean	:	
			rm -f *.o $(DEPENDS)

fclean	:	clean
			rm -f $(NAME)

x		:	all
			./$(NAME)

leaks	:	all
			leaks --atExit -- ./$(NAME)

re		:	fclean all

-include $(DEPENDS)
