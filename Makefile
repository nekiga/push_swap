# Colors
GREEN = \033[0;92m
DEFAULT = \033[0;39m

CC = gcc
SRC = push_swap moves aux test al3

NAME = push_swap.a

all: $(NAME)

$(NAME): $(SRC:=.o)
	@echo "$(GREEN)\nCompiling...\n$(DEFAULT)"
	ar rcs $(NAME) $(SRC:=.o)
	$(CC) -Wall -Werror -Wextra -g $(NAME) -o push
	@echo "$(GREEN)\nDone compiling...\n$(DEFAULT)"
clean:
	rm -f $(SRC:=.o)
fclean:
	@echo "$(GREEN)\nCleaning up...\n$(DEFAULT)"
	rm -f $(SRC:=.o) $(NAME) push.exe
		@echo "$(GREEN)\nDone cleaning...\n$(DEFAULT)"
re: fclean all

