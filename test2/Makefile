NAME = push_swap
SRC = libft.c libft2.c list.c list2.c list3.c sort.c instruction.c instruction2.c instruction3.c insertion.c bouble.c atoi_error.c main.c list4.c
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