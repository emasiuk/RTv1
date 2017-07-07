/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:22:18 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:22:18 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t len)
{
	int		i;
	size_t	j;

	i = -1;
	j = -1;
	while (dest[++i])
		;
	while (src[++j] && j < len)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
