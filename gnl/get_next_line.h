/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:30:16 by enja              #+#    #+#             */
/*   Updated: 2023/04/26 16:41:25 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 256

int		ft_strlenn(char *str);
char	*join(char *str, char *buff);
char	*get_next_line(int fd);
int		check_n(char *last);
char	*check_befor_n(char	*str);
char	*check_after_n(char *str, int len);
char	*ft_strdupp(char	*str);
#endif