/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:11:53 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:11:54 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		ch_buff;

	i = 0;
	while (n-- > 0)
	{
		ch_buff = ((unsigned char *)src)[i];
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		if (ch_buff == (unsigned char)c)
			return (&dst[i]);
	}
	return (NULL);
}
