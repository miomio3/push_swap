NAME = push_swap.out
SRC = libft.c push_swap.c atoi_error.c list.c sort.c
CC = gcc
FLUG = -Wall -Werror -Wextra

all		:$(NAME)
$(NAME)	:$(SRC)
	$(CC) $(FLUG) $(SRC) -o $(NAME)
clean	:
	rm -f $(NAME)
fclean	:
	rm -f $(NAME)
re		:fclean all

.PHONY	:re clean fclean all