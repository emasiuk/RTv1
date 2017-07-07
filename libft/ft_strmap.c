/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:36:13 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 20:36:13 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s_buff;
	char	*str;
	size_t	i;

	if (s == '\0')
		return (NULL);
	i = 0;
	if ((str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	if ((s_buff = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	ft_strcpy(s_buff, s);
	while (i < ft_strlen(s))
	{
		str[i] = f(s_buff[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
