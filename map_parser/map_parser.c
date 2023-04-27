/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:12:08 by enja              #+#    #+#             */
/*   Updated: 2023/04/27 19:02:12 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

char	*check_sides(char *tab)
{
	char	*str;
	int		fd;

	str = manage_spaces(tab);
	check_extention(str, 2);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_msg(4);
	return (str);
}

t_sides	*get_sides(char **tab, t_sides *sides)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp("NO", tab[i], 2) == 0)
			sides->no = check_sides(&tab[i][2]);
		else if (ft_strncmp("SO", tab[i], 2) == 0)
			sides->so = check_sides(&tab[i][2]);
		else if (ft_strncmp("WE", tab[i], 2) == 0)
			sides->we = check_sides(&tab[i][2]);
		else if (ft_strncmp("EA", tab[i], 2) == 0)
			sides->ea = check_sides(&tab[i][2]);
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

void	check_data_colors(t_sides *colors)
{
	char	**tab_f;
	char	**tab_c;

	tab_f = ft_split(colors->f, ',');
	tab_c = ft_split(colors->c, ',');
	if (tdm(tab_f) != 3 || tdm(tab_c) != 3)
		error_msg(4);
	int i = 0;
	while (tab_c[i])
		printf("%s\n", tab_c[i++]);
}

t_sides	*check_colors(char **tab, t_sides *colors)
{
	int	i;

	i = 4;
	while (i < 6)
	{
		if (tab[i][0] == 'F')
			colors->f = manage_spaces(&tab[i][1]);
		else if (tab[i][0] == 'C')
			colors->c = manage_spaces(&tab[i][1]);
		i++;
	}
	if (!colors->c || !colors->f)
		error_msg(4);
	check_data_colors(colors);
	return (colors);
}

char	*pars_data(char **tab)
{
	t_sides	*sides;

	if (tdm(tab) < 7)
		error_msg(4);
	sides = malloc(1 * sizeof(t_sides));
	sides = init_data_null(sides);
	sides = get_sides(tab, sides);
	if (!sides->ea || !sides->no || !sides->so || !sides->we)
		error_msg(4);
	sides = check_colors(tab, sides);
	return (NULL);
}
