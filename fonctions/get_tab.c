/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:29:47 by enja              #+#    #+#             */
/*   Updated: 2023/05/04 17:34:49 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fonctions.h"

int	tdm(char **arr)
{
	int	a;

	if (!arr || arr[0] == NULL)
		return (0);
	a = 0;
	while (arr[a] != NULL)
		a++;
	return (a);
}

char	**get_tab(char **cmd_table, char *newcmd)
{
	int		i;
	char	**newtable;

	i = 0;
	if (!cmd_table)
	{
		cmd_table = malloc(2 * sizeof(char *));
		cmd_table[0] = newcmd;
		cmd_table[1] = NULL;
		return (cmd_table);
	}
	newtable = malloc((tdm(cmd_table) + 2) * sizeof(char *));
	while (cmd_table[i])
	{
		newtable[i] = cmd_table[i];
		i++;
	}
	newtable[i++] = newcmd;
	newtable[i] = NULL;
	free(cmd_table);
	return (newtable);
}
