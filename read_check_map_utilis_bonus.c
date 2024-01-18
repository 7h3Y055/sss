/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map_utilis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:38:55 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/16 20:38:59 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_components_helper(t_components *content, char c)
{
	if (c == '1')
		content->one++;
	else if (c == '0')
		content->zero++;
	else if (c == 'E')
		content->e++;
	else if (c == 'C')
		content->c++;
	else if (c == 'P')
		content->p++;
	else if (c == 'X')
		content->x++;
	else if (!(c == '\n' || c == '\r'))
		content->others++;
}

int	check_components(char *map)
{
	int				i;
	t_components	*content;

	i = 0;
	content = ft_calloc(sizeof(t_components), 1);
	while (map[i])
	{
		check_components_helper(content, map[i]);
		i++;
	}
	if (content->others || !content->c || content->e != 1 || content->p != 1)
		return (free(map), free(content), 1);
	return (free(content), 0);
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
	while (map_2d[1][++i])
		if (map_2d[1][i] != '1' || map_2d[y - 1][i] != '1')
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
