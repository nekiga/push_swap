# Colors
GREEN = \033[0;92m
DEFAULT = \033[0;39m

CC = cc
SRC =  moves moves1 aux algo auxalgo auxalgo1 auxalgo2 aux1 aux2 aux3 algo5 push_swap

NAME = push_swap.a

$(VERBOSE).SILENT:

all: $(NAME)

$(NAME): $(SRC:=.o)
	ar rcs $(NAME) $(SRC:=.o)
	$(CC) -Wall -Werror -Wextra -g  $(NAME) -o push_swap
	@echo "$(GREEN)\n\t\tDone compiling...\n$(DEFAULT)"
clean:
	rm -f $(SRC:=.o)
fclean:
	rm -f $(SRC:=.o) $(NAME) push.exe
		@echo "$(GREEN)\n\t\tDone cleaning...\n$(DEFAULT)"
re: fclean all

