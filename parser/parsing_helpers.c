/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:04:40 by enja              #+#    #+#             */
/*   Updated: 2023/05/20 17:22:15 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/includes.h"

void	error_msg(int sig)
{
	if (sig == 1)
		printf("Few Or Many Arguments !\n");
	if (sig == 2)
		printf("Wrong Extention !\n");
	if (sig == 3)
		printf("No Such Map File !\n");
	if (sig == 4)
		printf("Map Data Error !\n");
	// system("leaks cub3D");
	exit(1);
}

t_elements	*init_data_null(t_elements *elmnt, t_side_f *f, t_side_c *c)
{
	elmnt->ea = NULL;
	elmnt->no = NULL;
	elmnt->so = NULL;
	elmnt->we = NULL;
	elmnt->c = NULL;
	elmnt->f = NULL;
	elmnt->sid_f = f;
	elmnt->sid_c = c;
	return (elmnt);
}

int	ascii_toint(char *str)
{
	int	value;
	int	range;

	value = 0;
	range = 0;
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		str++;
		range++;
		if (range >= 4)
			error_msg(4);
	}
	if (value > 255)
		error_msg(4);
	return (value);
}

int	hole_dir(char c, int sig)
{
	if (sig == 1)
	{
		if (c == ' ' || c == '\t')
			return (1);
		return (0);
	}
	if (sig == 23)
	{
		if (c == '0' || c == '1' || c == 'N' || c == ' ' \
			|| c == 'S' || c == 'E' || c == 'W' || c == '\t')
			return (0);
		return (1);
	}
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

void	check_extention(char *path, int sig)
{
	int		size;
	int		i;
	char	*ext;

	if (sig == 1)
		ext = ".cub";
	else if (sig == 2)
		ext = ".xpm";
	size = ft_strlen(path) - 1;
	i = 3;
	while (i >= 0)
	{
		if (ext[i] == path[size])
		{
			i--;
			size--;
		}
		else
		{
			if (sig == 2)
				free(path);
			error_msg(2);
		}
	}
}
