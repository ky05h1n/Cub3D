/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:42:19 by enja              #+#    #+#             */
/*   Updated: 2023/04/28 21:41:03 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes.h"

int	check_num(int c)
{
	printf("- >> %c\n", c);
	if (c >= '0' && c <= '9')
		return (1);
	else
	{
		error_msg(4);
		return (0);
	}
}

char	**get_map(char **av)
{
	char	*str;
	char	**tab;
	int		fd;
	int		count;

	count = 0;
	tab = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_msg(3);
	str = get_next_line(fd);
	while (str)
	{
		if (scan_line(str) == 1)
		{
			if (count < 6)
			{
				str = ft_strtrim(str, "\n");
				count++;
			}
			tab = get_tab(tab, str);
		}
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
	char	**tab;

	parameter_analyzer(ac, av);
	tab = get_map(av);
	pars_data(tab);
}
