/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:12:08 by enja              #+#    #+#             */
/*   Updated: 2023/04/26 20:51:51 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_sides	*check_sides(char **tab, t_sides *sides)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp("NO", tab[i], 2) == 0)
		{
			sides->no = manage_spaces(&tab[i][2]);
			printf("no --->%s\n", sides->no);
		}
		else if (ft_strncmp("SO", tab[i], 2) == 0)
		{
			sides->so = manage_spaces(&tab[i][2]);
			printf("so --->%s\n", sides->so);
		}
		else if (ft_strncmp("WE", tab[i], 2) == 0)
		{
			sides->we = manage_spaces(&tab[i][2]);
			printf("we --->%s\n", sides->we);
		}
		else if (ft_strncmp("EA", tab[i], 2) == 0)
		{
			sides->ea = manage_spaces(&tab[i][2]);
			printf("ea --->%s\n", sides->ea);
		}
		i++;
	}
	return (sides);
}

int	scan_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

char	*manage_spaces(char *str)
{
	int		i;
	int		end;
	char	*string;

	string = NULL;
	i = 0;
	end = ft_strlen(str) - 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (end >= 0 && (str[end] == ' ' || str[end] == '\t'))
		end--;
	while (str[i] && i <= end)
	{
		string = get_char(string, str[i]);
		i++;
	}
	return (string);
}

char	*pars_data(char **tab)
{
	t_sides	*sides;

	sides = malloc(1 * sizeof(t_sides));
	sides->ea = NULL;
	sides->no = NULL;
	sides->so = NULL;
	sides->we = NULL;
	sides = check_sides(tab, sides);
	if (!sides->ea || !sides->no || !sides->so || !sides->we)
	{
		printf("no valid sides\n");
		exit(1);
	}
	return (NULL);
}
