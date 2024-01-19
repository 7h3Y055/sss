/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:50:57 by ybouchma          #+#    #+#             */
/*   Updated: 2023/11/15 09:00:21 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *arg, ...);
int	print_char(int c);
int	print_str(char *str);
int	print_addr(void *ptr);
int	print_int(int n);
int	print_uint(unsigned int n);
int	print_hex(unsigned int n, char c);
#endif
