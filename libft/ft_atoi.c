/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:21:21 by enja              #+#    #+#             */
/*   Updated: 2023/04/29 14:23:06 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	value;
	int	range;

	sign = 1;
	value = 0;
	range = 0;
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		str++;
		range++;
		if (range >= 20 && sign == -1)
			return (0);
		if (range >= 20 && sign == 1)
			return (-1);
	}
	return (value * sign);
}
