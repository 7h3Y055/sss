/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:37:15 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/19 11:59:00 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1337
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*read_data(int fd, char *buffer);
int		read_data_helper(char **buffer, char *data);
char	*get_nline(char *buffer);
char	*clean(char *buffer);
void	*ft_calloc_copy(size_t n, size_t size);
char	*merge(char *s1, char *s2);
size_t	ft_strlen_copy(const char *str);
char	*ft_strdup_copy(char *src);
void	*ft_bzero_copy(void *s, size_t n);
char	*ft_strchr_copy(const char *s, int c);
#endif
