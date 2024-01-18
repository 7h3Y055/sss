/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_utilis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <ybouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:16:38 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/15 16:17:33 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_available_coins(t_so_long *ptr)
{
	size_t	c;
	int		pp[2];
	char	**map_2d;

	create_2d_map(ptr->map, &map_2d);
	get_player_position(pp, map_2d);
	c = back_track_coin_counter(ptr, map_2d, pp[0], pp[1]);
	free_map(map_2d);
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
