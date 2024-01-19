SRC =	ft_toupper.c	ft_substr.c		ft_tolower.c		\
		ft_atoi.c		ft_bzero.c		ft_calloc.c			\
		ft_isalnum.c	ft_isalpha.c	ft_isascii.c		\
		ft_isdigit.c	ft_isprint.c	ft_itoa.c			\
		ft_memchr.c		ft_memcmp.c		ft_memcpy.c			\
		ft_memmove.c	ft_memset.c		ft_putchar_fd.c		\
		ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c		\
		ft_split.c		ft_strchr.c		ft_strdup.c			\
		ft_striteri.c	ft_strjoin.c	ft_strlcat.c		\
		ft_strlcpy.c	ft_strlen.c		ft_strmapi.c		\
		ft_strncmp.c	ft_strnstr.c	ft_strrchr.c		\
		ft_strtrim.c	
SRC_B = ft_lstnew.c		ft_lstiter.c	ft_lstadd_front.c	\
		ft_lstclear.c	ft_lstlast.c	ft_lstdelone.c		\
		ft_lstmap.c		ft_lstsize.c	ft_lstadd_back.c
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJ = $(subst .c,.o,$(SRC))
OBJ_B = $(subst .c,.o,$(SRC_B))


all:$(OBJ)
	ar -rcs $(NAME) $(OBJ)
$(NAME):all
clean:
	rm -f $(OBJ) $(OBJ_B)
fclean:clean
	rm -f $(NAME)
re:fclean all
bonus:$(OBJ_B)
	ar -rcs $(NAME) $(OBJ_B)
