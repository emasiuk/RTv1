/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:25:07 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:25:09 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, const char *src, unsigned int num)
{
	unsigned int i;

	i = -1;
	while (src[++i] && (0 < num))
	{
		dest[i] = src[i];
		num--;
	}
	while (num > 0)
	{
		dest[i] = '\0';
		i++;
		num--;
	}
	return (dest);
}
