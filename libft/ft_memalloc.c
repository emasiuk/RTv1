/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:56:04 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:56:05 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*s;
	size_t	temp;

	temp = -1;
	s = malloc(size);
	if (s == 0)
		return (0);
	while (++temp < size)
		(*((unsigned char*)(s + temp))) = 0;
	return (s);
}
