SRCS = ft_printf.c srcs/print_addr.c srcs/print_char.c srcs/print_hex.c srcs/print_int.c srcs/print_str.c srcs/print_uint.c
OBJ  = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a


$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)
all:$(NAME)
clean:
	rm -f $(OBJ)
fclean:clean
	rm -f $(NAME)
re:fclean $(NAME)
