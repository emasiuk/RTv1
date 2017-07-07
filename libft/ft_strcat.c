/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:16:29 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:16:30 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	j = -1;
	i = -1;
	while (dest[++i])
		;
	while (src[++j])
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}
