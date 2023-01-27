CC = gcc
SRC = push_swap moves aux

NAME = push_swap.a

all: $(NAME)

$(NAME): $(SRC:=.o)
	ar rcs $(NAME) $(SRC:=.o)
	$(CC) -Wall -g $(NAME) -o push
clean:
	rm -f $(SRC:=.o)
fclean:
	rm -f $(SRC:=.o) $(NAME) push

re: fclean all
