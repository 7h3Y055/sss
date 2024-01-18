/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map_utilis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <ybouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:35:12 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/15 16:13:49 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_and_check_map_helper(char *map, char **map_2d)
{
	if (check_components(map))
		return (free_map(map_2d), \
			ft_putendl_fd("[!MAP] Contain invalid component", 2), NULL);
	if (check_rectangular(map_2d))
		return (free(map), free_map(map_2d), \
			ft_putendl_fd("[!MAP] Not rectangular", 2), NULL);
	if (check_closed(map_2d))
		return (free(map), free_map(map_2d), \
			ft_putendl_fd("[!MAP] Not closed by wall", 2), NULL);
	if (check_valid_path(map))
		return (free_map(map_2d), \
		ft_putendl_fd("[!MAP] Invalid path", 2), NULL);
	if (check_coins(map, map_2d))
		return (free_map(map_2d), \
		ft_putendl_fd("[!MAP] Player can't collet all coins", 2), NULL);
	return (free_map(map_2d), map);
}

int	check_rectangular(char **map_2d)
{
	int		i;

	i = 1;
	while (map_2d[i])
	{
		if (ft_strlen(map_2d[i - 1]) != ft_strlen(map_2d[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_closed(char **map_2d)
{
	int		i;
	int		y;

	y = 0;
	while (map_2d[y])
		y++;
	i = -1;
	while (map_2d[0][++i])
		if (map_2d[0][i] != '1' || map_2d[y - 1][i] != '1')
			return (1);
	i = 0;
	while (map_2d[i] && map_2d[i][0])
	{
		if (map_2d[i][0] != '1' || map_2d[i][ft_strlen(map_2d[0]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_path(char *map)
{
	char	**map_2d;
	int		player_position[2];

	if (create_2d_map(map, &map_2d))
		return (1);
	get_player_position(player_position, map_2d);
	if (!valid_path(map_2d, player_position[0], player_position[1]))
		return (free_map(map_2d), free(map), 1);
	free_map(map_2d);
	return (0);
}
