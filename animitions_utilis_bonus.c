/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animitions_utilis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:39:36 by ybouchma          #+#    #+#             */
/*   Updated: 2024/01/17 10:39:38 by ybouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_enemy_flags(t_so_long *ptr, int *x)
{
	if (*x == 0)
	{
		if (ptr->flag)
			ptr->flag = 0;
		else
			ptr->flag = 1;
		*x = 1;
	}
	else
		*x = 0;
}
