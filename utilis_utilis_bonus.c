/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_utilis_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:17:54 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/17 11:18:50 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	check_minimal_space(char **map_2d, int y, int x)
{
	size_t	c;

	c = 0;
	if (map_2d[y - 1][x] == 'C')
	{
		c++;
		map_2d[y - 1][x] = '0';
	}
	if (map_2d[y + 1][x] == 'C')
	{
		c++;
		map_2d[y + 1][x] = '0';
	}
	if (map_2d[y][x - 1] == 'C')
	{
		c++;
		map_2d[y][x - 1] = '0';
	}
	if (map_2d[y][x + 1] == 'C')
	{
		c++;
		map_2d[y][x + 1] = '0';
	}
	return (c);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

size_t	map_x_len(char *map)
{
	int	x;

	x = 0;
	while (map[x] && map[x] != '\n')
		x++;
	return (x);
}

size_t	map_y_len(char *map)
{
	int		i;
	size_t	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
			i++;
		i++;
		y++;
	}
	return (y);
}
