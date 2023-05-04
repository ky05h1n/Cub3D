/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:38:15 by enja              #+#    #+#             */
/*   Updated: 2023/05/04 18:46:44 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fonctions.h"

char	*ft_strdup(char *s1)

{
	int		i;
	int		j;
	char	*p;

	i = 0;
	while (s1[i])
		i++;
	p = malloc (i + 1 * sizeof(char));
	if (!p)
		return (NULL);
	else
	{
		j = 0;
		while (j < i)
		{
			p[j] = s1[j];
			j++;
		}
	}
	p[j] = '\0';
	return (p);
}
