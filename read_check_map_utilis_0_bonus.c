/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map_utilis_0.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:40:11 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/16 20:40:33 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_wall(char *map)
{
	int	i;

	i = ft_strlen(map) - 1;
	while (i >= 0 && map[i] != '\n')
		i--;
	i--;
	while (i >= 0 && map[i] != '\n')
		i--;
	return (&map[++i]);
}

int	create_2d_map(char *map, char ***map_2d)
{
	int	i;
	int	j;
	int	u;

	map_2d[0] = malloc(sizeof(char *) * (map_y_len(map) + 3));
	if (!map_2d[0])
		return (free(map), 1);
	map_2d[0][0] = ft_strdup(get_wall(map));
	map_2d[0][0][ft_strlen(map_2d[0][0]) - 1] = 0;
	i = 0;
	j = 0;
	u = 1;
	while (map[i])
	{
		map_2d[0][u] = malloc(sizeof(char) * (map_x_len(map) + 1));
		j = 0;
		while (map[i] && !(map[i] == '\n' || map[i] == '\r'))
			map_2d[0][u][j++] = map[i++];
		map_2d[0][u][j] = 0;
		u++;
		i++;
	}
	map_2d[0][u] = NULL;
	return (0);
}
