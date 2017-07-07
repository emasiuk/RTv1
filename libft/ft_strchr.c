/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:17:41 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:17:41 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return ((char*)&s[i]);
	}
	if (s[i] == '\0' && c == '\0')
		return ((char*)&s[i]);
	return (0);
}
