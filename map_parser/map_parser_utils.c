/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:04:40 by enja              #+#    #+#             */
/*   Updated: 2023/04/26 14:50:49 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	tdm(char **arr)
{
	int	a;

	if (arr[0] == NULL)
		return (0);
	a = 0;
	while (arr[a] != NULL)
		a++;
	return (a);
}

char	*get_char(char *str, char c)
{
	char	*strnw;
	int		i;

	i = 0;
	if (!str)
	{
		str = malloc (sizeof(char) * 2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	strnw = malloc((ft_strlen(str) + 2) * sizeof(char));
	while (str[i])
	{
		strnw[i] = str[i];
		i++;
	}
	strnw[i++] = c;
	strnw[i] = '\0';
	free(str);
	return (strnw);
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
