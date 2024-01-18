/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:13:37 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/16 11:48:47 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	counter_helper_1(t_so_long *ptr, char c, int x)
{
	if (c == '0')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
			ptr->assets.num.zero, (x * 32) + 14, 8);
	if (c == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
			ptr->assets.num.one, (x * 32) + 14, 8);
	if (c == '2')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
			ptr->assets.num.two, (x * 32) + 14, 8);
	if (c == '3')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
			ptr->assets.num.three, (x * 32) + 14, 8);
	if (c == '4')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
			ptr->assets.num.foor, (x * 32) + 14, 8);
}

void	counter_helper_2(t_so_long *ptr, char c, int x)
{
	if (c == '5')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
			ptr->assets.num.five, (x * 32) + 14, 8);
	if (c == '6')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
			ptr->assets.num.six, (x * 32) + 14, 8);
	if (c == '7')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
			ptr->assets.num.seven, (x * 32) + 14, 8);
	if (c == '8')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
			ptr->assets.num.eight, (x * 32) + 14, 8);
	if (c == '9')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, \
			ptr->assets.num.nine, (x * 32) + 14, 8);
}

void	counter(t_so_long *ptr)
{
	char	*number;
	int		i;
	int		x;

	number = ft_itoa(ptr->counter);
	x = (map_x_len(ptr->map) - 1) / 2 + (ft_strlen(number) / 2);
	i = ft_strlen(number) - 1;
	while (i >= 0)
	{
		counter_helper_1(ptr, number[i], x);
		counter_helper_2(ptr, number[i], x);
		x--;
		i--;
	}
	free(number);
}
