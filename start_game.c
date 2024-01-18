/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:51:22 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/17 12:33:14 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	animations(t_so_long *ptr)
{
	int	pp[2];

	get_player_position(pp, ptr->map_2d);
	if (pp[0] == ptr->ep[0] && pp[1] == ptr->ep[1])
		win(ptr);
	if (ptr->available_coins == 0 && ptr->exit)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
		ptr->assets.door.open, ptr->ep[1] * 32, ptr->ep[0] * 32);
		ptr->exit = 0;
	}
	init_assets_in_window(ptr);
	return (0);
}

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
	{
		ft_printf("[SO_LONG] Game closed by user.\n");
		destroy_all(ptr, 1);
	}
	return (0);
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
	if (c == 'C')
		return (ptr->assets.coin);
	return (NULL);
}

void	init_assets_in_window(t_so_long *ptr)
{
	size_t	y;
	size_t	x;
	void	*asset;

	y = 0;
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
}

int	start_game(char *map)
{
	t_so_long	ptr;

	ptr.mlx = mlx_init();
	if (!ptr.mlx)
		return (1);
	ptr.mlx_win = mlx_new_window(ptr.mlx, \
	(map_x_len(map)) * 32, (map_y_len(map)) * 32, "SO_LONG");
	if (!ptr.mlx_win)
		return (mlx_destroy_display(ptr.mlx), 1);
	ptr.map = map;
	if (create_2d_map(map, &ptr.map_2d))
		return (mlx_destroy_window(ptr.mlx, \
		ptr.mlx_win), mlx_destroy_display(ptr.mlx), 1);
	init_flags(&ptr);
	get_exit_position(ptr.ep, &ptr);
	init_assets(&ptr);
	init_assets_in_window(&ptr);
	mlx_key_hook(ptr.mlx_win, handle_input, &ptr);
	mlx_hook(ptr.mlx_win, DestroyNotify, ButtonPressMask, destroy_all, &ptr);
	mlx_loop_hook(ptr.mlx, animations, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
