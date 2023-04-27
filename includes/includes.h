/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:47:18 by enja              #+#    #+#             */
/*   Updated: 2023/04/27 18:00:06 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct sides
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		r;
	int		g;
	int		b;
}t_sides;

int		tdm(char **arr);
char	*get_char(char *str, char c);
char	**get_tab(char **cmd_table, char *newcmd);
char	*pars_data(char **tab);
char	*manage_spaces(char *str);
int		scan_line(char *str);
t_sides	*get_sides(char **tab, t_sides *sides);
t_sides	*check_colors(char **tab, t_sides *colors);
t_sides	*init_data_null(t_sides *sides);
void	error_msg(int sig);
void	parameter_analyzer(int ac, char **av);
void	check_extention(char *ext, int sig);
char	*check_sides(char *tab);
void	check_data_colors(t_sides *colors);
#endif
