/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:19:51 by enja              #+#    #+#             */
/*   Updated: 2021/11/22 22:12:12 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	idx;
	size_t	zy;
	char	*typstr;

	idx = 0;
	typstr = (char *)str;
	if (ft_strlen(tofind) == 0)
		return (typstr);
	while (str[idx] && idx < len)
	{
		zy = 0;
		while (typstr[idx + zy] == tofind[zy] && idx + zy < len)
		{
			if (tofind[zy + 1] == '\0')
				return (&typstr[idx]);
			zy++;
		}
		idx++;
	}
	return (NULL);
}
