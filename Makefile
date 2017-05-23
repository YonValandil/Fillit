#Regles qui ne concerne pas des noms de fichiers
.PHONY: clean fclean re
#Enleve les directives implicites par defauts
.SUFFIXES:

CC =		gcc
EXEC =		fillit
NAME =		ft
SRCS_DIR =	./srcs/
OBJS_DIR =	./
LIB_DIR = 	./libft/
HEADER =	./includes/
CFLAGS =	-Wall -Werror -Wextra
ARFLAGS =	-rcs
CFILES =	main fillit

#pattern sub : $(var:pattern=replacement)
SRCS =		$(CFILES:%=$(SRCS_DIR)%.c)
OBJS =		$(SRCS:%.c=$(OBJS_DIR)%.o)

all:
	make -C libft/
	$(CC) $(SRCS) -I$(HEADER) -L$(LIB_DIR) -l$(NAME) -o $(EXEC) $(CFLAGS)

clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	@echo $@ Done !

fclean:		clean
	rm -f $(EXEC)
	@make -C libft/ fclean
	@echo $@ Done !

re:			fclean all
