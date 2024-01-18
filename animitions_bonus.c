/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animitions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:15:32 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/17 12:44:57 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	coin_animition_helper(t_so_long *ptr, void **asset, int n)
{
	if (n == 0)
		*asset = ptr->assets.coin.a;
	if (n == 1)
		*asset = ptr->assets.coin.b;
	if (n == 2)
		*asset = ptr->assets.coin.c;
	if (n == 3)
		*asset = ptr->assets.coin.d;
	if (n == 4)
		*asset = ptr->assets.coin.e;
	if (n == 5)
		*asset = ptr->assets.coin.f;
	if (n == 6)
		*asset = ptr->assets.coin.g;
	if (n == 7)
		*asset = ptr->assets.coin.h;
}

void	coin_animition(t_so_long *ptr, int *coin_speed)
{
	static int	n;
	int			cp[2];
	void		*asset;

	if (coin_speed)
		*coin_speed = 0;
	coin_animition_helper(ptr, &asset, n);
	cp[0] = 0;
	while (ptr->map_2d[cp[0]])
	{
		cp[1] = 0;
		while (ptr->map_2d[cp[0]][cp[1]])
		{
			if (ptr->map_2d[cp[0]][cp[1]] == 'C')
				mlx_put_image_to_window(ptr->mlx, \
						ptr->mlx_win, asset, cp[1] * 32, cp[0] * 32);
			cp[1]++;
		}
		cp[0]++;
	}
	if (n == 7)
		n = 0;
	else
		n++;
}

void	enemy_animation_helper(t_so_long *ptr, int *ep)
{
	if (ptr->map_2d[ep[0]][ep[1] + 1] == '0' && ptr->flag == 0)
	{
		ptr->map_2d[ep[0]][ep[1] + 1] = 'X';
		mlx_put_image_to_window(ptr->mlx, \
		ptr->mlx_win, ptr->assets.enemy, (ep[1] + 1) * 32, ep[0] * 32);
		ptr->map_2d[ep[0]][ep[1]] = '0';
		mlx_put_image_to_window(ptr->mlx, \
		ptr->mlx_win, ptr->assets.floor, ep[1] * 32, ep[0] * 32);
	}
	else if (ptr->map_2d[ep[0]][ep[1] + 1] == 'P' && ptr->flag == 0)
		player_killed(ptr);
	if (ptr->map_2d[ep[0]][ep[1] - 1] == '0' && ptr->flag)
	{
		ptr->map_2d[ep[0]][ep[1] - 1] = 'X';
		mlx_put_image_to_window(ptr->mlx, \
			ptr->mlx_win, ptr->assets.enemy, (ep[1] - 1) * 32, ep[0] * 32);
		ptr->map_2d[ep[0]][ep[1]] = '0';
		mlx_put_image_to_window(ptr->mlx, \
			ptr->mlx_win, ptr->assets.floor, ep[1] * 32, ep[0] * 32);
	}
	else if (ptr->map_2d[ep[0]][ep[1] - 1] == 'P' && ptr->flag)
		player_killed(ptr);
}

void	enemy_animation(t_so_long *ptr, int *enemy_speed)
{
	int			ep[2];
	static int	x;

	*enemy_speed = 0;
	ep[0] = 0;
	while (ptr->map_2d[ep[0]])
	{
		ep[1] = 0;
		while (ptr->map_2d[ep[0]][ep[1]])
		{
			if (ptr->map_2d[ep[0]][ep[1]] == 'X')
			{
				enemy_animation_helper(ptr, ep);
				ep[1]++;
			}
			ep[1]++;
		}
		ep[0]++;
	}
	handle_enemy_flags(ptr, &x);
}

int	animations(t_so_long *ptr)
{
	static int	enemy_speed;
	static int	coin_speed;
	static int	rerendering;
	int			pp[2];

	get_player_position(pp, ptr->map_2d);
	if (pp[0] == ptr->ep[0] && pp[1] == ptr->ep[1])
		win(ptr);
	//destroy_all(ptr, 1);
	if (ptr->available_coins == 0 && ptr->exit)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
		ptr->assets.door.open, ptr->ep[1] * 32, ptr->ep[0] * 32);
		ptr->exit = 0;
	}
	if (rerendering >= 70)
		init_assets_in_window(ptr);
	if (enemy_speed >= ENEMY_SPEED)
		enemy_animation(ptr, &enemy_speed);
	if (coin_speed >= COIN_SPEED)
		coin_animition(ptr, &coin_speed);
	enemy_speed++;
	coin_speed++;
	rerendering++;
	usleep(20000);
	return (0);
}
