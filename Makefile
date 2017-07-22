.PHONY: clean fclean re
.SUFFIXES:

CC =		gcc
EXEC =		fillit
LIB =		ft
SRCS_DIR =	./srcs/
OBJS_DIR =	./
LIB_DIR = 	./libft/
HEADER =	./includes/
CFLAGS =	-Wall -Werror -Wextra -g
ARFLAGS =	-rcs
CFILES =	main fillit

SRCS =		$(CFILES:%=$(SRCS_DIR)%.c)
OBJS =		$(SRCS:%.c=$(OBJS_DIR)%.o)

all:
	make -C libft/
	$(CC) $(SRCS) -I$(HEADER) -L$(LIB_DIR) -l$(LIB) -o $(EXEC)

clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	@echo $@ Done !

fclean:		clean
	rm -f $(EXEC)
	@make -C libft/ fclean
	@echo $@ Done !

re:			fclean all
