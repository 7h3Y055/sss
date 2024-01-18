/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utilis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:16:05 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/17 11:47:39 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_assets_helper(t_so_long ptr)
{
	mlx_destroy_image(ptr.mlx, ptr.assets.wall);
	mlx_destroy_image(ptr.mlx, ptr.assets.num.eight);
	mlx_destroy_image(ptr.mlx, ptr.assets.num.five);
	mlx_destroy_image(ptr.mlx, ptr.assets.num.foor);
	mlx_destroy_image(ptr.mlx, ptr.assets.num.nine);
	mlx_destroy_image(ptr.mlx, ptr.assets.num.one);
	mlx_destroy_image(ptr.mlx, ptr.assets.num.seven);
	mlx_destroy_image(ptr.mlx, ptr.assets.num.six);
	mlx_destroy_image(ptr.mlx, ptr.assets.num.three);
	mlx_destroy_image(ptr.mlx, ptr.assets.num.two);
	mlx_destroy_image(ptr.mlx, ptr.assets.num.zero);
	mlx_destroy_image(ptr.mlx, ptr.assets.black);
}

void	destroy_assets(t_so_long ptr)
{
	mlx_destroy_image(ptr.mlx, ptr.assets.coin.a);
	mlx_destroy_image(ptr.mlx, ptr.assets.coin.b);
	mlx_destroy_image(ptr.mlx, ptr.assets.coin.c);
	mlx_destroy_image(ptr.mlx, ptr.assets.coin.d);
	mlx_destroy_image(ptr.mlx, ptr.assets.coin.e);
	mlx_destroy_image(ptr.mlx, ptr.assets.coin.f);
	mlx_destroy_image(ptr.mlx, ptr.assets.coin.g);
	mlx_destroy_image(ptr.mlx, ptr.assets.coin.h);
	mlx_destroy_image(ptr.mlx, ptr.assets.door.close);
	mlx_destroy_image(ptr.mlx, ptr.assets.door.open);
	mlx_destroy_image(ptr.mlx, ptr.assets.enemy);
	mlx_destroy_image(ptr.mlx, ptr.assets.floor);
	mlx_destroy_image(ptr.mlx, ptr.assets.player.back);
	mlx_destroy_image(ptr.mlx, ptr.assets.player.front);
	mlx_destroy_image(ptr.mlx, ptr.assets.player.left);
	mlx_destroy_image(ptr.mlx, ptr.assets.player.right);
	destroy_assets_helper(ptr);
}

int	destroy_all(t_so_long *ptr, int flag)
{
	if (flag)
		destroy_assets(*ptr);
	mlx_destroy_window(ptr->mlx, ptr->mlx_win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	free(ptr->map);
	free_map(ptr->map_2d);
	exit(0);
}

void	get_exit_position(int *ep, t_so_long *ptr)
{
	ep[0] = 0;
	while (ep[0] < (int)map_y_len(ptr->map))
	{
		ep[1] = 0;
		while (ep[1] < (int)map_x_len(ptr->map))
		{
			if (ptr->map_2d[ep[0]][ep[1]] == 'E')
				return ;
			ep[1]++;
		}
		ep[0]++;
	}
}
