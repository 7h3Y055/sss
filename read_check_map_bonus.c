/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:08:00 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/16 20:40:44 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long_bonus.h"

int	read_and_check_map_helper(char *map, char **map_2d)
{
	if (check_components(map))
		return (free_map(map_2d), \
		ft_putendl_fd("[!MAP] Contain invalid component", 2), 1);
	else if (check_rectangular(map_2d))
		return (free(map), free_map(map_2d), \
		ft_putendl_fd("[!MAP] Not rectangular", 2), 1);
	else if (check_closed(map_2d))
		return (free(map), free_map(map_2d), \
		ft_putendl_fd("[!MAP] Not closed by wall", 2), 1);
	else if (check_valid_path(map))
		return (free_map(map_2d), \
		ft_putendl_fd("[!MAP] Invalid path", 2), 1);
	else if (check_coins(map, map_2d))
		return (free_map(map_2d), \
		ft_putendl_fd("[!MAP] Player can't collet all coins", 2), 1);
	else
		return (0);
}

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
	if (read_and_check_map_helper(map, map_2d))
		return (NULL);
	return (free_map(map_2d), map);
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
