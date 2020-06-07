##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## repository Makefile
## EXAMPLE DE MAKEFILE POUR COMPILER UNE LIBRAIRIE
##

SRCGAMES =	Sfml.cpp

OBJGAMES	=	$(SRCGAMES:.cpp=.o)

DIR	=	../

DIRINCL	=	../../../include/

CC	=	g++

CPPFLAGS	=	-std=c++17 -Wall -Werror -Wextra -I$(DIRINCL) $(SOB)

LDFLAGS	=	

LDLIBS	=

PATHGAMESDIR	=	../../../lib/

NAME	=	lib_arcade_sfml

RM	=	rm -f

SOB	=	-fPIC

SOA	=	-shared

MV	=	mv

LIBSHAREDNAME	=	$(NAME).so

COMPLIB	=	ar rc

all:	$(LIBSHAREDNAME)

$(LIBSHAREDNAME):	$(OBJGAMES)
		$(CC) -lsfml-graphics -lsfml-window -lsfml-system $(SOA) -o $(LIBSHAREDNAME) $(OBJGAMES)
		$(MV) $(LIBSHAREDNAME) $(PATHGAMESDIR)

clean:
	$(RM) $(OBJGAMES)
fclean:	clean
	$(RM) $(PATHGAMESDIR)$(LIBSHAREDNAME)

re:	fclean all

.PHONY:	clean fclean re
