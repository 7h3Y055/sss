/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:45:43 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/17 12:31:46 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long_bonus.h"
#include <fcntl.h>

void	init_assets_player(t_so_long *ptr, int w)
{
	ptr->assets.player.back = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/player/back.xpm", &w, &w);
	ptr->assets.player.front = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/player/front.xpm", &w, &w);
	ptr->assets.player.left = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/player/left.xpm", &w, &w);
	ptr->assets.player.right = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/player/right.xpm", &w, &w);
}

void	init_assets_coin(t_so_long *ptr, int w)
{
	ptr->assets.coin.a = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/coins/c1.xpm", &w, &w);
	ptr->assets.coin.b = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/coins/c2.xpm", &w, &w);
	ptr->assets.coin.c = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/coins/c3.xpm", &w, &w);
	ptr->assets.coin.d = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/coins/c4.xpm", &w, &w);
	ptr->assets.coin.e = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/coins/c5.xpm", &w, &w);
	ptr->assets.coin.f = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/coins/c6.xpm", &w, &w);
	ptr->assets.coin.g = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/coins/c7.xpm", &w, &w);
	ptr->assets.coin.h = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/coins/c8.xpm", &w, &w);
}

void	init_assets_number(t_so_long *ptr, int w)
{
	ptr->assets.num.zero = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/numbers/0.xpm", &w, &w);
	ptr->assets.num.one = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/numbers/1.xpm", &w, &w);
	ptr->assets.num.two = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/numbers/2.xpm", &w, &w);
	ptr->assets.num.three = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/numbers/3.xpm", &w, &w);
	ptr->assets.num.foor = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/numbers/4.xpm", &w, &w);
	ptr->assets.num.five = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/numbers/5.xpm", &w, &w);
	ptr->assets.num.six = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/numbers/6.xpm", &w, &w);
	ptr->assets.num.seven = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/numbers/7.xpm", &w, &w);
	ptr->assets.num.eight = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/numbers/8.xpm", &w, &w);
	ptr->assets.num.nine = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/numbers/9.xpm", &w, &w);
}

void	assets_not_found(t_so_long *ptr)
{
	ft_putendl_fd("[ERROR] Please go to main derectory and run game.", 2);
	destroy_all(ptr, 0);
	(void)ptr;
	exit(1);
}

void	init_assets(t_so_long *ptr)
{
	int	w;
	int	test;

	w = 0;
	test = open("./textures/black.xpm", O_RDONLY);
	if (test == -1)
		assets_not_found(ptr);
	close(test);
	init_assets_player(ptr, w);
	init_assets_coin(ptr, w);
	init_assets_number(ptr, w);
	ptr->assets.door.close = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/door/close.xpm", &w, &w);
	ptr->assets.door.open = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/door/open.xpm", &w, &w);
	ptr->assets.enemy = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/enemy.xpm", &w, &w);
	ptr->assets.wall = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/wall.xpm", &w, &w);
	ptr->assets.floor = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/floor.xpm", &w, &w);
	ptr->assets.black = mlx_xpm_file_to_image(\
			ptr->mlx, "./textures/black.xpm", &w, &w);
}

void	*get_asset(t_so_long *ptr, char c)
{
	if (c == '1')
		return (ptr->assets.wall);
	if (c == '0')
		return (ptr->assets.floor);
	if (c == 'P')
	{
		if (ptr->last_pp == 1)
			return (ptr->assets.player.back);
		if (ptr->last_pp == 4)
			return (ptr->assets.player.left);
		if (ptr->last_pp == 3)
			return (ptr->assets.player.front);
		if (ptr->last_pp == 2)
			return (ptr->assets.player.right);
	}
	if (c == 'E')
	{
		if (ptr->exit)
			return (ptr->assets.door.close);
		else
			return (ptr->assets.door.open);
	}
	if (c == 'X')
		return (ptr->assets.enemy);
	return (NULL);
}
