/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:14:57 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/17 12:32:16 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# define W 119
# define D 100
# define S 115
# define A 97

typedef struct s_player
{
	void	*front;
	void	*back;
	void	*left;
	void	*right;

}	t_player;

typedef struct s_door
{
	void	*open;
	void	*close;
}	t_door;

typedef struct s_assets
{
	t_player	player;
	t_door		door;
	void		*coin;
	void		*wall;
	void		*floor;
}	t_assets;

typedef struct s_so_long
{
	void		*mlx;
	void		*mlx_win;
	char		*map;
	char		**map_2d;
	t_assets	assets;
	int			exit;
	int			available_coins;
	int			ep[2];
	int			flag;
	int			counter;
	int			last_pp;
}	t_so_long;

typedef struct s_components
{
	int	one;
	int	zero;
	int	c;
	int	e;
	int	p;
	int	others;
}	t_components;

char	*read_and_check_map(int fd);
char	*read_map(int fd);
int		check_components(char *map);
int		check_rectangular(char **map_2d);
int		check_closed(char **map_2d);
int		create_2d_map(char *map, char ***map_2d);
int		check_valid_path(char *map);
void	free_map(char **map);
size_t	map_x_len(char *map);
size_t	map_y_len(char *map);
void	get_player_position(int *pp, char **map_2d);
int		valid_path(char **map, int y, int x);
int		start_game(char *map);
void	go_up(t_so_long *ptr);
void	go_down(t_so_long *ptr);
void	go_left(t_so_long *ptr);
void	go_rigth(t_so_long *ptr);
size_t	count_available_coins(t_so_long *ptr);
int		destroy_all(t_so_long *ptr, int flag);
void	player_killed(t_so_long *ptr);
int		check_coins(char *map, char **map_2d);
void	init_assets_in_window(t_so_long *ptr);
void	win(t_so_long *ptr);
void	init_assets_player(t_so_long *ptr, int w);
void	get_exit_position(int *ep, t_so_long *ptr);
void	init_assets(t_so_long *ptr);
void	init_flags(t_so_long *ptr);
char	*read_and_check_map_helper(char *map, char **map_2d);
size_t	back_track_coin_counter(t_so_long *ptr, char **map_2d, int y, int x);

#endif
