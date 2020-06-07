##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## repository Makefile
## EXAMPLE DE MAKEFILE POUR COMPILER UNE LIBRAIRIE
##

NAME	=	libmy_sharedgraphics

GR1	=	ncurses/

GR2	=	sfml/

NAME	=	libs

LIBSHAREDNAME	=	$(NAME).so

COMPLIB	=	ar rc

all:	$(LIBSHAREDNAME)

$(LIBSHAREDNAME):
	(cd $(GR1); make all)
	(cd $(GR2); make all)

clean:
	(cd $(GR1); make clean)
	(cd $(GR2); make clean)

fclean:	clean
	(cd $(GR1); make fclean)
	(cd $(GR2); make fclean)


re:	fclean all

.PHONY:	clean fclean re
