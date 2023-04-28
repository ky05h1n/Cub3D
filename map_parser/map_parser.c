/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:12:08 by enja              #+#    #+#             */
/*   Updated: 2023/04/28 21:43:27 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

char	*check_sides(char *tab)
{
	char	*str;
	int		fd;

	str = manage_spaces(tab);
	printf("%s\n", str);
	check_extention(str, 2);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_msg(4);
	return (tab);
}

t_sides	*check_elements(char **tab, t_sides *elm)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp("NO", tab[i], 2) == 0)
			elm->no = check_sides(&tab[i][2]);
		else if (ft_strncmp("SO", tab[i], 2) == 0)
			elm->so = check_sides(&tab[i][2]);
		else if (ft_strncmp("WE", tab[i], 2) == 0)
			elm->we = check_sides(&tab[i][2]);
		else if (ft_strncmp("EA", tab[i], 2) == 0)
			elm->ea = check_sides(&tab[i][2]);
		else if (ft_strncmp("F", tab[i], 1) == 0)
			elm->f = manage_spaces(&tab[i][1]);
		else if (ft_strncmp("C", tab[i], 1) == 0)
			elm->c = manage_spaces(&tab[i][1]);
		i++;
	}
	if (!elm->ea || !elm->no || !elm->so || !elm->we || !elm->f || !elm->c)
		error_msg(4);
	return (elm);
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
	//int		end;
	char	*string;

	string = NULL;
	i = 0;
	//end = ft_strlen(str) - 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	// while (end >= 0 && (str[end] == ' ' || str[end] == '\t'))
	// 	end--;
	while (str[i])
	{
		string = get_char(string, str[i]);
		i++;
	}
	return (string);
}

void	check_data_colors(t_sides *colors)
{
	char	*str_f = NULL;
	char	*str_c = NULL;
	int		count = 0;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (colors->f[i] || colors->c[n])
	{
		if (colors->f[i] && colors->f[i] != ',' && check_num(colors->f[i]) == 1)
			str_f = get_char(str_f, colors->f[i]);
		if (colors->c[n] && colors->c[n] != ',' && check_num(colors->c[n]) == 1)
			str_c = get_char(str_c, colors->c[n]);
		if (colors->f[i] == ',' || colors->c[n] == ',')
			count++;
		if (colors->f[i])
			i++;
		if (colors->c[n])
			n++;
	}
	//if (count != 4)
	//	error_msg(4);
}

char	*pars_data(char **tab)
{
	t_sides	*sides;

	if (tdm(tab) < 7)
		error_msg(4);
	sides = malloc(1 * sizeof(t_sides));
	sides = init_data_null(sides);
	sides = check_elements(tab, sides);
	check_data_colors(sides);
	return (NULL);
}
