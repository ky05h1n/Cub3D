/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:47:18 by enja              #+#    #+#             */
/*   Updated: 2023/05/04 19:28:34 by enja             ###   ########.fr       */
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
# include "../headers/fonctions.h"

typedef struct side_f
{
	int	f_r;
	int	f_g;
	int	f_b;
}t_side_f;

typedef struct side_c
{
	int	c_r;
	int	c_g;
	int	c_b;
}t_side_c;

typedef struct elements
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		**map;
	t_side_f	*sid_f;
	t_side_c	*sid_c;
}t_elements;

int			tdm(char **arr);
t_elements	*pars_data(char **tab, t_elements *elements);
char		*manage_spaces(char *str, int sig);
int			scan_line(char *str, int count);
t_elements	*check_elements(char **tab, t_elements *sides);
t_elements	*check_colors(char **tab, t_elements *colors);
t_elements	*init_data_null(t_elements *elmnt, t_side_f *f, t_side_c *c);
void		error_msg(int sig);
void		parameter_analyzer(int ac, char **av, int *fd);
void		check_extention(char *ext, int sig);
char		*check_sides(char *tab);
void		check_data_colors(t_elements *elmnt);
char		*check_num(char *str);
t_elements	*set_data_colors(t_elements *elements);
int			ascii_toint(char *str);
t_elements	*pars_map(t_elements *elements);
char		**check_remove(char **map);
void		check_walls(char **map);
void		check_holes(char **map, int i, int n);
int			hole_dir(char c, int sig);

#endif
