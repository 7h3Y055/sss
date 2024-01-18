NAME = so_long
NAMEB = so_long_bonus
SRCS = moves.c read_check_map.c read_check_map_utilis.c so_long.c start_game.c start_game_utilis_0.c start_game_utilis.c utilis.c utilis_utilis.c
SRCSB = animitions_bonus.c animitions_utilis_bonus.c counter_bonus.c init_assets_bonus.c messges_bonus.c moves_bonus.c read_check_map_bonus.c read_check_map_utilis_0_bonus.c read_check_map_utilis_bonus.c so_long_bonus.c start_game_bonus.c start_game_utilis_bonus.c utilis_bonus.c utilis_utilis_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
CFLAGS = -Wall -Werror -Wextra -L/usr/lib -lXext -lX11
LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx_Linux.a

all:$(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	gcc $(OBJS) $(MLX) $(LIBFT) $(CFLAGS) -o $(NAME)

$(NAMEB):bonus 

bonus: $(OBJSB) $(LIBFT) $(MLX)
	gcc $(OBJSB) $(MLX) $(LIBFT) $(CFLAGS) -o $(NAMEB)

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(OBJSB)
fclean: clean
	make fclean -C ./libft
	make clean -C ./minilibx-linux
	rm -f $(NAME) $(NAMEB)

re:fclean all

