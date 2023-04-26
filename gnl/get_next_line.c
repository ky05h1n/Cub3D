/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:29:58 by enja              #+#    #+#             */
/*   Updated: 2023/04/26 13:17:33 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenn(char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char	*join(char *str, char *buff)
{
	char	*final;
	int		len;
	int		n;
	int		i;

	if (!str)
		return (ft_strdupp(buff));
	i = 0;
	n = 0;
	len = ft_strlenn(str) + ft_strlenn(buff);
	final = malloc(len + 1);
	while (str[i])
	{
		final[i] = str[i];
		i++;
	}
	while (buff[n])
	{
		final[i++] = buff[n++];
	}
	final[i] = '\0';
	free(str);
	return (final);
}

char	*buff_read(char *temp, int fd)
{
	char		*buff;
	int			n;

	n = 1;
	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	while (check_n(temp) == -1 && n != 0)
	{	
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(temp);
			free(buff);
			temp = NULL;
			return (temp);
		}
		buff[n] = '\0';
		temp = join(temp, buff);
	}
	if (ft_strlenn(temp) == 0 && n == 0)
	{
		free(temp);
		temp = NULL;
	}
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp = NULL;
	char		*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_n(temp) == -1)
		temp = buff_read(temp, fd);
	if (!temp)
		return (NULL);
	if (check_n(temp) != -1)
	{
		string = check_befor_n(temp);
		temp = check_after_n(temp, check_n(temp) + 1);
		return (string);
	}
	string = temp;
	temp = NULL;
	return (string);
}
