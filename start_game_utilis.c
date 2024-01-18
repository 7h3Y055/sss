/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utilis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:56:32 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/17 12:35:03 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_assets(t_so_long ptr)
{
	mlx_destroy_image(ptr.mlx, ptr.assets.coin);
	mlx_destroy_image(ptr.mlx, ptr.assets.door.close);
	mlx_destroy_image(ptr.mlx, ptr.assets.door.open);
	mlx_destroy_image(ptr.mlx, ptr.assets.floor);
	mlx_destroy_image(ptr.mlx, ptr.assets.player.back);
	mlx_destroy_image(ptr.mlx, ptr.assets.player.front);
	mlx_destroy_image(ptr.mlx, ptr.assets.player.left);
	mlx_destroy_image(ptr.mlx, ptr.assets.player.right);
	mlx_destroy_image(ptr.mlx, ptr.assets.wall);
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

char	*winner(void)
{
	char	*str;

	str = "	                  ███                                             \n\
                 ░░░                                              \n\
 █████ ███ █████ ████  ████████   ████████    ██████  ████████    \n\
░░███ ░███░░███ ░░███ ░░███░░███ ░░███░░███  ███░░███░░███░░███   \n\
 ░███ ░███ ░███  ░███  ░███ ░███  ░███ ░███ ░███████  ░███ ░░░    \n\
 ░░███████████   ░███  ░███ ░███  ░███ ░███ ░███░░░   ░███        \n\
  ░░████░████    █████ ████ █████ ████ █████░░██████  █████       \n\
   ░░░░ ░░░░    ░░░░░ ░░░░ ░░░░░ ░░░░ ░░░░░  ░░░░░░  ░░░░░        \n\
   	                  ███                                             \n\
                 ░░░                                              \n\
 █████ ███ █████ ████  ████████   ████████    ██████  ████████    \n\
░░███ ░███░░███ ░░███ ░░███░░███ ░░███░░███  ███░░███░░███░░███   \n\
 ░███ ░███ ░███  ░███  ░███ ░███  ░███ ░███ ░███████  ░███ ░░░    \n\
 ░░███████████   ░███  ░███ ░███  ░███ ░███ ░███░░░   ░███        \n\
  ░░████░████    █████ ████ █████ ████ █████░░██████  █████       \n\
   ░░░░ ░░░░    ░░░░░ ░░░░ ░░░░░ ░░░░ ░░░░░  ░░░░░░  ░░░░░        \n";
	return (str);
}

void	win(t_so_long *ptr)
{
	char	*str;

	str = "          █████       ███           █████                         \n\
         ░░███       ░░░           ░░███                          \n\
  ██████  ░███████   ████   ██████  ░███ █████  ██████  ████████  \n\
 ███░░███ ░███░░███ ░░███  ███░░███ ░███░░███  ███░░███░░███░░███ \n\
░███ ░░░  ░███ ░███  ░███ ░███ ░░░  ░██████░  ░███████  ░███ ░███ \n\
░███  ███ ░███ ░███  ░███ ░███  ███ ░███░░███ ░███░░░   ░███ ░███ \n\
░░██████  ████ █████ █████░░██████  ████ █████░░██████  ████ █████\n\
 ░░░░░░  ░░░░ ░░░░░ ░░░░░  ░░░░░░  ░░░░ ░░░░░  ░░░░░░  ░░░░ ░░░░░ \n\
     █████  ███                                                   \n\
    ░░███  ░░░                                                    \n\
  ███████  ████  ████████   ████████    ██████  ████████          \n\
 ███░░███ ░░███ ░░███░░███ ░░███░░███  ███░░███░░███░░███         \n\
░███ ░███  ░███  ░███ ░███  ░███ ░███ ░███████  ░███ ░░░          \n\
░███ ░███  ░███  ░███ ░███  ░███ ░███ ░███░░░   ░███              \n\
░░████████ █████ ████ █████ ████ █████░░██████  █████             \n\
 ░░░░░░░░ ░░░░░ ░░░░ ░░░░░ ░░░░ ░░░░░  ░░░░░░  ░░░░░              \n";
	ft_printf("\033[0;32m%s%s", winner(), str);
	destroy_all(ptr, 1);
}
