/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:01 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/19 12:03:36 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_copy(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

int	read_data_helper(char **buffer, char *data)
{
	int	i;

	if (ft_strlen_copy(*buffer) == 0)
	{
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
	if (ft_strchr_copy(*buffer, '\n'))
		return (1);
	i = 0;
	while (i < BUFFER_SIZE + 1)
		data[i++] = 0;
	return (0);
}

char	*ft_strdup_copy(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * ft_strlen_copy(src) + 1);
	if (dup == NULL)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen_copy(const char *str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc_copy(size_t n, size_t size)
{
	size_t	i;
	void	*ptr;

	if (size && SIZE_MAX / size <= n)
		return (NULL);
	ptr = malloc(size * n);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (n * size))
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}
