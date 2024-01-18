#include "so_long.h"

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

size_t	back_track_coin_counter(t_so_long *ptr, char **map_2d, int y, int x)
{
	size_t	c;

	c = check_minimal_space(map_2d, y, x);
	map_2d[y][x] = '1';
	if (map_2d[y - 1][x] == '0')
		c += back_track_coin_counter(ptr, map_2d, y - 1, x);
	if (map_2d[y + 1][x] == '0')
		c += back_track_coin_counter(ptr, map_2d, y + 1, x);
	if (map_2d[y][x - 1] == '0')
		c += back_track_coin_counter(ptr, map_2d, y, x - 1);
	if (map_2d[y][x + 1] == '0')
		c += back_track_coin_counter(ptr, map_2d, y, x + 1);
	return (c);
}

void	get_player_position(int *pp, char **map_2d)
{
	pp[0] = 0;
	while (map_2d[pp[0]])
	{
		pp[1] = 0;
		while (map_2d[pp[0]][pp[1]])
		{
			if (map_2d[pp[0]][pp[1]] == 'P')
				return ;
			pp[1]++;
		}
		pp[0]++;
	}
}

int	valid_path(char **map, int y, int x)
{
	if (map[y - 1][x] == 'E')
		return (1);
	else if (map[y + 1][x] == 'E')
		return (1);
	else if (map[y][x - 1] == 'E')
		return (1);
	else if (map[y][x + 1] == 'E')
		return (1);
	map[y][x] = '1';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		if (valid_path(map, y - 1, x))
			return (1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		if (valid_path(map, y + 1, x))
			return (1);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		if (valid_path(map, y, x - 1))
			return (1);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		if (valid_path(map, y, x + 1))
			return (1);
	return (0);
}
