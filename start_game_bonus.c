/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:45:25 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/17 11:50:57 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_input(int key, t_so_long *ptr)
{
	if (key == W)
		go_up(ptr);
	if (key == A)
		go_rigth(ptr);
	if (key == S)
		go_down(ptr);
	if (key == D)
		go_left(ptr);
	if (key == XK_Escape)
		destroy_all(ptr, 1);
	return (0);
}

void	init_black_part(t_so_long *ptr)
{
	size_t	x;

	x = 0;
	while (ptr->map_2d[0][x])
	{
		mlx_put_image_to_window(ptr->mlx, \
				ptr->mlx_win, ptr->assets.black, x * 32, 0);
		x++;
	}
}

void	init_assets_in_window(t_so_long *ptr)
{
	size_t	y;
	size_t	x;
	void	*asset;

	y = 1;
	while (ptr->map_2d[y])
	{
		x = 0;
		while (ptr->map_2d[y][x])
		{
			asset = get_asset(ptr, ptr->map_2d[y][x]);
			if (asset)
				mlx_put_image_to_window(ptr->mlx, \
					ptr->mlx_win, asset, x * 32, y * 32);
			x++;
		}
		y++;
	}
	init_black_part(ptr);
	counter(ptr);
}

void	inits_values(t_so_long *ptr)
{
	get_exit_position(ptr->ep, ptr);
	ptr->available_coins = count_available_coins(ptr);
	ptr->exit = 1;
	ptr->flag = 1;
	ptr->counter = 0;
	ptr->last_pp = 3;
}

int	start_game(char *map)
{
	t_so_long	ptr;

	ptr.mlx = mlx_init();
	if (!ptr.mlx)
		return (1);
	ptr.mlx_win = mlx_new_window(ptr.mlx, (map_x_len(map)) \
			* 32, (map_y_len(map) + 1) * 32, "BONUS");
	if (!ptr.mlx_win)
		return (mlx_destroy_display(ptr.mlx), 1);
	ptr.map = map;
	if (create_2d_map(map, &ptr.map_2d))
		return (mlx_destroy_window(ptr.mlx, ptr.mlx_win), \
				mlx_destroy_display(ptr.mlx), 1);
	inits_values(&ptr);
	init_assets(&ptr);
	init_assets_in_window(&ptr);
	coin_animition(&ptr, NULL);
	counter(&ptr);
	mlx_key_hook(ptr.mlx_win, handle_input, &ptr);
	mlx_hook(ptr.mlx_win, DestroyNotify, ButtonPressMask, destroy_all, &ptr);
	mlx_loop_hook(ptr.mlx, animations, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
