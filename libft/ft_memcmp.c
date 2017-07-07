/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:46:21 by emasiuk           #+#    #+#             */
/*   Updated: 2016/12/05 12:46:21 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*dest2;

	dest1 = (unsigned char*)str1;
	dest2 = (unsigned char*)str2;
	while (n--)
	{
		if (*dest1 - *dest2)
			return ((int)(*dest1 - *dest2));
		else
		{
			dest1++;
			dest2++;
		}
	}
	return (0);
}
