/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:04:57 by enja              #+#    #+#             */
/*   Updated: 2023/04/30 16:34:39 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zy_extract(char *s, int start, int len)
{
	char	*dst;
	int		a;

	a = 0;
	dst = malloc(len + 1 * sizeof(char));
	if (!dst)
		return (NULL);
	while (a < len)
	{
		dst[a++] = s[start++];
	}
		dst[a] = '\0';
	free(s);
	return (dst);
}

static int	zy_begtrim(char *str, char *trm)
{
	int	aix;
	int	i;

	aix = 0;
	i = 0;
	while (trm[aix])
	{
		if (trm[aix] == *str)
		{
			str++;
			i++;
			aix = 0;
		}
		else
			aix++;
	}
	return (i);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		aix;
	int		bix;
	int		hold;

	aix = 0;
	hold = 0;
	if (!s1)
		return (NULL);
	hold = zy_begtrim(s1, set);
	bix = ft_strlen(s1) - 1;
	if (hold == bix + 1)
		return (ft_strdup(""));
	while (set[aix])
	{
		if (set[aix] == s1[bix])
		{
			bix--;
			aix = 0;
		}
		else
			aix++;
	}
	return (zy_extract(s1, hold, bix - hold + 1));
}
