/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:47:14 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 19:47:15 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = -1;
	if ((s = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	while (++i <= size)
		s[i] = 0;
	s[i] = '\0';
	return (s);
}
