##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## repository Makefile
##

SRC	=	$(DIR)Arcade.cpp	\
		$(DIR)main.cpp

OBJ	=	$(SRC:.cpp=.o)

DIR	=	src/

DIRLIB	=	src/lib/

DIRGAME	=	src/games/

CC	=	g++

CPPFLAGS	=	-std=c++17 -Wall -Werror -Wextra -Iinclude -g3

LDFLAGS	=

LDLIBS	=

NAME	=	arcade

LIBNAME	=	libmy.a

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) -ldl
	## make graphicals
	(cd $(DIRLIB); make all)
	## make games
	(cd $(DIRGAME); make all)
	## make core

core:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) -ldl

games:
	(cd $(DIRGAME); make all)

graphicals:	
	(cd $(DIRLIB); make all)

clean:
	$(RM) $(OBJ)
	@(cd $(DIRLIB); make clean)
	@(cd $(DIRGAME); make clean)

fclean:	clean
	$(RM) *.txt
	$(RM) $(NAME)
	$(RM) $(LIBSHAREDNAME)
	@(cd $(DIRLIB); make fclean)
	@(cd $(DIRGAME); make fclean)

re:	fclean all

.PHONY:	clean fclean re
