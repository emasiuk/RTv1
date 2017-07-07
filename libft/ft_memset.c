/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:13:56 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:13:58 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *memptr, int val, size_t num)
{
	size_t		i;
	char		*s;

	s = memptr;
	i = -1;
	while (++i < num)
		s[i] = (unsigned char)val;
	return (memptr);
}
