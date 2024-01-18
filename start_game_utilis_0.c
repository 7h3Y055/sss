/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utilis_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:58:47 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/17 12:31:42 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_not_found(t_so_long *ptr)
{
	ft_putendl_fd("[ERROR] Please go to main derectory and run game.", 2);
	destroy_all(ptr, 0);
	(void)ptr;
	exit(1);
}

void	init_assets_player(t_so_long *ptr, int w)
{
	ptr->assets.player.back = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/player/back.xpm", &w, &w);
	ptr->assets.player.front = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/player/front.xpm", &w, &w);
	ptr->assets.player.left = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/player/left.xpm", &w, &w);
	ptr->assets.player.right = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/player/right.xpm", &w, &w);
}

void	init_assets(t_so_long *ptr)
{
	int	test;
	int	w;

	w = 0;
	test = open("./textures/black.xpm", O_RDONLY);
	if (test == -1)
		assets_not_found(ptr);
	close(test);
	init_assets_player(ptr, w);
	ptr->assets.coin = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/coin-bag.xpm", &w, &w);
	ptr->assets.door.close = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/door/close.xpm", &w, &w);
	ptr->assets.door.open = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/door/open.xpm", &w, &w);
	ptr->assets.wall = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/wall.xpm", &w, &w);
	ptr->assets.floor = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/floor.xpm", &w, &w);
}

void	init_flags(t_so_long *ptr)
{
	ptr->available_coins = count_available_coins(ptr);
	ptr->exit = 1;
	ptr->flag = 1;
	ptr->last_pp = 3;
	ptr->counter = 0;
}
