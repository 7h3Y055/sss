/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:51:33 by ybouchma          #+#    #+#             */
/*   Updated: 2023/11/15 09:02:00 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_str(char *str)
{
	int	len;

	if (!str)
	{
		print_str("(null)");
		return (6);
	}
	len = 0;
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}
