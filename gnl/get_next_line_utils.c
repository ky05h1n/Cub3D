/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:26:49 by enja              #+#    #+#             */
/*   Updated: 2023/04/26 13:30:59 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_n(char *last)
{
	int	a;

	a = 0;
	if (!last)
		return (-1);
	while (last[a])
	{
		if (last[a] == '\n')
			return (a);
		a++;
	}
	return (-1);
}

char	*check_befor_n(char	*str)
{
	int		n;
	char	*exclude_n;

	n = 0;
	exclude_n = malloc(ft_strlenn(str) + 1);
	while (str[n] && str[n] != '\n')
	{
			exclude_n[n] = str[n];
			n++;
	}
	exclude_n[n] = str[n];
	n++;
	exclude_n[n] = '\0';
	return (exclude_n);
}

char	*ft_strdupp(char	*str)
{
	char	*dest;
	int		a;
	int		len;

	a = 0;
	len = ft_strlenn(str);
	dest = malloc(len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	while (str[a])
	{
		dest[a] = str[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*check_after_n(char *str, int len)
{
	char	*ret;

	ret = ft_strdupp(str + len);
	free(str);
	return (ret);
}
