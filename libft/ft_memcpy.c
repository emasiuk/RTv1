/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:12:44 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:12:45 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t		i;
	char		*s;
	char		*b;

	b = dest;
	s = (char*)src;
	i = -1;
	while (++i < num)
		b[i] = (unsigned char)s[i];
	return (dest);
}
