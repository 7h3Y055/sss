/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:29:12 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/15 16:14:12 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_and_check_map(int fd)
{
	char	*map;
	char	*tmp;
	char	**map_2d;

	tmp = read_map(fd);
	if (tmp[ft_strlen(tmp) - 1] != '\n')
	{
		map = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	else
		map = tmp;
	create_2d_map(map, &map_2d);
	return (read_and_check_map_helper(map, map_2d));
}

int	check_coins(char *map, char **map_2d)
{
	t_so_long	ptr;
	int			y;
	int			x;
	size_t		c;

	c = 0;
	y = 0;
	while (map_2d[y])
	{
		x = 0;
		while (map_2d[y][x])
		{
			if (map_2d[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	ptr.map_2d = map_2d;
	ptr.map = map;
	if (c != count_available_coins(&ptr))
		return (free(map), 1);
	return (0);
}

char	*read_map(int fd)
{
	char	*map;
	char	*tmp;
	char	*tmp2;

	map = (char *)ft_calloc(1, 1);
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp2 = ft_strjoin(map, tmp);
		free(tmp);
		free(map);
		map = tmp2;
	}
	return (map);
}

int	create_2d_map(char *map, char ***map_2d)
{
	int	i;
	int	j;
	int	u;

	map_2d[0] = malloc(sizeof(char *) * (map_y_len(map) + 2));
	if (!map_2d[0])
		return (free(map), 1);
	i = 0;
	j = 0;
	u = 0;
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

int	check_components(char *map)
{
	int				i;
	t_components	*content;

	i = 0;
	content = ft_calloc(sizeof(t_components), 1);
	while (map[i])
	{
		if (map[i] == '1')
			content->one++;
		else if (map[i] == '0')
			content->zero++;
		else if (map[i] == 'E')
			content->e++;
		else if (map[i] == 'C')
			content->c++;
		else if (map[i] == 'P')
			content->p++;
		else if (!(map[i] == '\n' || map[i] == '\r'))
			content->others++;
		i++;
	}
	if (content->others || !content->c || content->e != 1 || content->p != 1)
		return (free(map), free(content), 1);
	return (free(content), 0);
}
