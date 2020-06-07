##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## repository Makefile
## EXAMPLE DE MAKEFILE POUR COMPILER UNE LIBRAIRIE
##

SRCLIB =	Ncurses.cpp

OBJLIB	=	$(SRCLIB:.cpp=.o)

DIR	=	../

DIRINCL	=	../../../include/

CC	=	g++

CPPFLAGS	=	-std=c++17 -Wall -Werror -Wextra -I$(DIRINCL) $(SOB) 

LDFLAGS	=	

LDLIBS	=

PATHLIBDIR	=	../../../lib/

NAME	=	lib_arcade_ncurses

RM	=	rm -f

SOB	=	-fPIC

SOA	=	-shared

MV	=	mv

LIBSHAREDNAME	=	$(NAME).so

COMPLIB	=	ar rc

all:	$(LIBSHAREDNAME)

$(LIBSHAREDNAME):	$(OBJLIB)
		$(CC) -lncurses $(SOA) -o $(LIBSHAREDNAME) $(OBJLIB)
		$(MV) $(LIBSHAREDNAME) $(PATHLIBDIR)

clean:
	$(RM) $(OBJLIB)

fclean:	clean
	$(RM) $(PATHLIBDIR)$(LIBSHAREDNAME)

re:	fclean all

.PHONY:	clean fclean re
