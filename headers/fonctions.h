/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:08:11 by zy0tsh1           #+#    #+#             */
/*   Updated: 2023/05/04 18:43:11 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTIONS_H
# define FONCTIONS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(const char *s, char c);
char	**get_tab(char **cmd_table, char *newcmd);
char	*get_char(char *str, char c);
int		tdm(char **arr);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strncmp(char *s1, char *s2, int n);

#endif