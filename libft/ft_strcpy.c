/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:25:35 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/21 14:26:13 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	count;

	count = -1;
	while (src[++count] != '\0')
		dst[count] = src[count];
	dst[count] = '\0';
	return (dst);
}
