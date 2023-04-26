/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:42:19 by enja              #+#    #+#             */
/*   Updated: 2023/04/26 20:25:10 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes.h"

char	**get_map(char **av)
{
	char	*str;
	char	**tab;
	int		fd;
	int		count;
	//int		i;

	count = 0;
	//i = 0;
	tab = NULL;
	fd = open(av[1], O_RDWR);
	if (fd == -1)
	{
		printf("no such file\n");
		exit(1);
	}
	str = get_next_line(fd);
	while (str)
	{
		if (scan_line(str) == 1)
		{
			if (count < 6)
			{
				str = ft_strtrim(str, "\n");
				str = manage_spaces(str);
				count++;
			}
			tab = get_tab(tab, str);
		}
		str = get_next_line(fd);
	}
	// while (tab[i])
	// 	printf("%s\n", tab[i++]);
	return (tab);
}

void	error_msg(int sig)
{
	if (sig == 1)
		printf("few argument\n");
	if (sig == 2)
		printf("wrong extention\n");
	exit(1);
}

void	parameter_analyzer(int ac, char **av)
{
	char	*ext;
	int		size;
	int		i;

	if (ac != 2)
		error_msg(1);
	ext = ".cub";
	size = ft_strlen(av[1]) - 1;
	i = 3;
	while (i >= 0)
	{
		if (ext[i] == av[1][size])
		{
			i--;
			size--;
		}
		else
			error_msg(2);
	}
}

int	main(int ac, char **av)
{
	char **tab;

	parameter_analyzer(ac, av);
	tab = get_map(av);
	pars_data(tab);
}
