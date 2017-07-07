/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:13:06 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:13:07 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int j;

	j = 0;
	if ((unsigned long)dst < (unsigned long)src)
	{
		while (n-- > 0)
		{
			((unsigned char *)dst)[j] = ((unsigned char *)src)[j];
			j++;
		}
	}
	else
		while (n-- > 0)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	return (dst);
}
