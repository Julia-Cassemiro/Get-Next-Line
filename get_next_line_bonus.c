/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:27:57 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/06/09 15:29:03 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_save_the_next(char *s)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	i++;
	while (s[i])
		str[count++] = s[i++];
	str[count] = '\0';
	free(s);
	return (str);
}

char	*ft_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save[OPEN_MAX];
	int			count;

	buff = ft_verific_buff(fd, line);
	if (!buff)
		return (-1);
	count = 1;
	while (ft_verific_newline(save[fd]) != 1 && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(buff);
			return (-1);
		}
		buff[count] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	free(buff);
	*line = ft_line(save[fd]);
	save[fd] = ft_save_the_next(save[fd]);
	if (count == 0)
		return (0);
	return (1);
}
