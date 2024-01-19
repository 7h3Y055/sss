NAME = so_long
NAMEB = so_long_bonus
SRCS = moves.c read_check_map.c read_check_map_utilis.c so_long.c start_game.c start_game_utilis_0.c start_game_utilis.c utilis.c utilis_utilis.c
SRCSB = animitions_bonus.c animitions_utilis_bonus.c counter_bonus.c init_assets_bonus.c messges_bonus.c moves_bonus.c read_check_map_bonus.c read_check_map_utilis_0_bonus.c read_check_map_utilis_bonus.c so_long_bonus.c start_game_bonus.c start_game_utilis_bonus.c utilis_bonus.c utilis_utilis_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx_Linux -lXext -lX11 -no-pie
LIBFT = ./libft/libft.a

all:$(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	gcc $(OBJS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

$(NAMEB):bonus 

bonus: $(OBJSB) $(LIBFT)
	gcc $(OBJSB) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAMEB)

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(OBJSB)
fclean: clean
	make fclean -C ./libft
	rm -f $(NAME) $(NAMEB)

re:fclean all

