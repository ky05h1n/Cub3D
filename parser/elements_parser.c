/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:12:08 by enja              #+#    #+#             */
/*   Updated: 2023/04/30 21:43:15 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_elements	*set_data_colors(t_elements *elements)
{
	char	**rgb_f;
	char	**rgb_c;

	rgb_f = ft_split(elements->f, ',');
	rgb_c = ft_split(elements->c, ',');
	if (tdm(rgb_f) != 3 || tdm(rgb_c) != 3)
		error_msg(4);
	elements->sid_f->f_r = ascii_toint(check_num(rgb_f[0]));
	elements->sid_f->f_g = ascii_toint(check_num(rgb_f[1]));
	elements->sid_f->f_b = ascii_toint(check_num(rgb_f[2]));
	elements->sid_c->c_r = ascii_toint(check_num(rgb_c[0]));
	elements->sid_c->c_g = ascii_toint(check_num(rgb_c[1]));
	elements->sid_c->c_b = ascii_toint(check_num(rgb_c[2]));
	return (elements);
}

char	*manage_spaces(char *str, int sig)
{
	int		i;
	char	*string;

	string = NULL;
	i = 0;
	if (sig == 2)
	{
		i = ft_strlen(str) - 1;
		while (str[i] == ' ' || str[i] == '\t')
			i--;
		sig = i;
		i = 0;
		while (str[i] && i <= sig)
			string = get_char(string, str[i++]);
		free(str);
		return (string);
	}
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		string = get_char(string, str[i]);
		i++;
	}
	return (string);
}

char	*check_sides(char *path)
{
	char	*str;
	int		fd;

	str = manage_spaces(path, 0);
	check_extention(str, 2);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_msg(4);
	return (str);
}

t_elements	*check_elements(char **tab, t_elements *elm)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp("NO ", tab[i], 3) == 0)
			elm->no = check_sides(&tab[i][2]);
		else if (ft_strncmp("SO ", tab[i], 3) == 0)
			elm->so = check_sides(&tab[i][2]);
		else if (ft_strncmp("WE ", tab[i], 3) == 0)
			elm->we = check_sides(&tab[i][2]);
		else if (ft_strncmp("EA ", tab[i], 3) == 0)
			elm->ea = check_sides(&tab[i][2]);
		else if (ft_strncmp("F ", tab[i], 2) == 0)
			elm->f = manage_spaces(&tab[i][1], 0);
		else if (ft_strncmp("C ", tab[i], 2) == 0)
			elm->c = manage_spaces(&tab[i][1], 0);
		i++;
	}
	if (!elm->ea || !elm->no || !elm->so || !elm->we || !elm->f || !elm->c)
		error_msg(4);
	if (elm->f[0] == ',' || elm->c[0] == ',' || elm->f[ft_strlen(elm->f) - 1]
		== ',' || elm->c[ft_strlen(elm->c) - 1] == ',')
		error_msg(4);
	return (elm);
}

t_elements	*pars_data(char **tab, t_elements *elements)
{
	if (tdm(tab) < 9)
		error_msg(4);
	elements = check_elements(tab, elements);
	elements = set_data_colors(elements);
	elements->map = &tab[6];
	elements = pars_map(elements);
	return (elements);
}
