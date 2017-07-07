/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:23:36 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:23:37 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				res;
	unsigned int	i;

	i = 0;
	res = 0;
	while (s1[i] && !(res) && i < (unsigned int)n)
	{
		res = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (!res && i != n)
		res = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (res);
}
