/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:00:25 by enja              #+#    #+#             */
/*   Updated: 2023/05/01 22:23:33 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

char	**check_remove(char **map)
{
	int		i;
	int		size;
	char	**newmap;

	newmap = NULL;
	size = tdm(map) - 1;
	while (scan_line(map[size], 98) == 0)
		size--;
	i = -1;
	while (map[++i] && i <= size)
	{
		if (scan_line(map[i], 98) == 0)
			error_msg(4);
		newmap = get_tab(newmap, manage_spaces(ft_strtrim(map[i], "\n"), 2));
	}
	return (newmap);
}

void	check_walls(char **map)
{
	int		i;
	char	*temp;

	i = -1;
	while (map[++i])
	{
		temp = manage_spaces(map[i], 98);
		if (temp[0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			error_msg(4);
		free(temp);
	}
	i = -1;
	while (map[0][++i])
	{
		if (!(map[0][i] == ' ' || map[0][i] == '1'))
			error_msg(4);
	}
	i = -1;
	while (map[tdm(map) - 1][++i])
	{
		if (!(map[tdm(map) - 1][i] == ' ' || map[tdm(map) - 1][i] == '1'))
			error_msg(4);
	}
}

int	hole_dir(char c, int sig)
{
	if (sig == 1)
	{
		if (c == ' ' || c == '\t')
			return (1);
		return (0);
	}
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	check_holes(char **map, int i, int n)
{
	if (ft_strlen(map[i - 1]) - 1 <= n || ft_strlen(map[i + 1]) - 1 <= n)
		error_msg(4);
	if (hole_dir(map[i - 1][n], 1) || hole_dir(map[i + 1][n], 1))
		error_msg(4);
	if (hole_dir(map[i - 1][n - 1], 1) || hole_dir(map[i - 1][n + 1], 1))
		error_msg(4);
	if (hole_dir(map[i + 1][n - 1], 1) || hole_dir(map[i + 1][n + 1], 1))
		error_msg(4);
	if (hole_dir(map[i][n - 1], 1) || hole_dir(map[i][n + 1], 1) || \
		hole_dir(map[i][n - 1], 1) || hole_dir (map[i][n + 1], 1))
		error_msg(4);
}

void	check_content(char **map)
{
	int	i;
	int	n;
	int	dir;

	i = 1;
	dir = 0;
	while (map[i])
	{
		n = 1;
		while (map[i][n])
		{
			if (map[i][n] == '0' || hole_dir(map[i][n], 98))
				check_holes(map, i, n);
			if (hole_dir(map[i][n], 98))
				dir++;
			n++;
		}
		i++;
	}
	if (dir != 1)
		error_msg(4);
}

t_elements	*pars_map(t_elements *elements)
{
	int	i;

	i = 0;
	elements->map = check_remove(elements->map);
	check_walls(elements->map);
	check_content(elements->map);
	return (elements);
}
//// separate getchar and get_tab in a library
