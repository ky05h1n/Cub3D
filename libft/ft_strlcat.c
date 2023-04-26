/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:22:33 by enja              #+#    #+#             */
/*   Updated: 2021/11/28 18:34:38 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	dlen;
	size_t	slen;
	size_t	allsize;
	size_t	cpy;

	if ((!dst && dstsize == 0) || dstsize == 0)
		return (ft_strlen(src) + dstsize);
	idx = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (slen + dstsize);
	allsize = ft_strlen(src) + ft_strlen(dst);
	cpy = dstsize - dlen;
	while (src[idx] && idx < cpy - 1)
	{
		dst[dlen] = src[idx];
		dlen++;
		idx++;
	}
	dst[dlen] = '\0';
	return (allsize);
}
