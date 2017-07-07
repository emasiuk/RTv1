/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:20:24 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:20:25 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*istr;
	int		i;

	i = -1;
	while (str[++i])
		;
	if (!(istr = (char*)malloc(i + 1)))
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		istr[i] = str[i];
		i++;
	}
	istr[i] = '\0';
	return (istr);
}
