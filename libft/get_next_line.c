/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:38:56 by emasiuk           #+#    #+#             */
/*   Updated: 2017/01/19 18:38:57 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "get_next_line.h"

char	*ft_strjoin_1(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == '\0' || s2 == '\0')
		return (0);
	if ((str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
		+ 1))) == NULL)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

int		check_enter(char **buff, char **line)
{
	int		i;
	char	*temp;

	i = -1;
	if (*buff)
	{
		temp = ft_strdup(*buff);
		while (temp[++i])
		{
			if (temp[i] == '\n')
			{
				*line = ft_strsub(temp, 0, i);
				free(temp);
				temp = ft_strsub(*buff, (i + 1), ft_strlen(*buff));
				free(*buff);
				*buff = ft_strdup(temp);
				free(temp);
				return (1);
			}
		}
		free(temp);
	}
	return (0);
}

int		check_end(char **buff, char **line)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (check_enter(buff, line) == 1)
		return (1);
	if (*buff)
	{
		temp = ft_strdup(*buff);
		while (temp[i])
		{
			if (temp[i + 1] == '\0')
			{
				*line = ft_strsub(temp, 0, (i + 1));
				*buff = NULL;
				free(temp);
				return (1);
			}
			i++;
		}
		free(temp);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buff[4096];
	char			str[BUFF_SIZE + 1];
	int				fp;

	if (fd < 0 || (fp = read(fd, str, 0)) < 0)
		return (-1);
	if (check_enter(&buff[fd], line) == 1)
		return (1);
	while ((fp = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[fp] = '\0';
		if (buff[fd])
			buff[fd] = ft_strjoin_1(buff[fd], str);
		else
			buff[fd] = ft_strdup(str);
		if (check_enter(&buff[fd], line) == 1)
			return (1);
	}
	if (fp < BUFF_SIZE)
	{
		if (check_end(&buff[fd], line) == 0)
			return (0);
	}
	return (1);
}
