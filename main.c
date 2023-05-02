/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:42:19 by enja              #+#    #+#             */
/*   Updated: 2023/05/01 15:30:31 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes.h"

int	ascii_toint(const char *str)
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
		if (range >= 4)
			error_msg(4);
	}
	if (value > 255)
		error_msg(4);
	return (value);
}

char	*check_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			error_msg(4);
	}
	return (str);
}

int	scan_line(char *str, int count)
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
	i = 0;
	while (str[i] && count < 5)
	{
		if (str[i] == ' ' || str[i] == '\t')
			error_msg(1);
		i++;
	}
	return (0);
}

char	**get_elements(char **av)
{
	char	*str;
	char	**tab;
	int		fd;
	int		count;

	count = -1;
	tab = NULL;
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		error_msg(3);
	str = get_next_line(fd);
	while (str)
	{
		if (scan_line(str, count) == 1)
		{
			if (++count < 6)
			{
				str = ft_strtrim(str, "\n");
				tab = get_tab(tab, str);
			}
		}
		if (count > 5)
			tab = get_tab(tab, str);
		str = get_next_line(fd);
	}
	return (tab);
}

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
	//system("leaks cub3D");
	exit(1);
}

void	parameter_analyzer(int ac, char **av)
{
	if (ac != 2)
		error_msg(1);
	check_extention(av[1], 1);
}

int	main(int ac, char **av)
{
	char		**tab;
	t_elements	*elements;
	t_side_f	*side_f;
	t_side_c	*side_c;

	parameter_analyzer(ac, av);
	tab = get_elements(av);
	elements = malloc(1 * sizeof(t_elements));
	side_f = malloc(1 * sizeof(t_side_f));
	side_c = malloc(1 * sizeof(t_side_c));
	elements = init_data_null(elements, side_f, side_c);
	elements = pars_data(tab, elements);
	//system("leaks cub3D");
}
