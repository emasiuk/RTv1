/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:25:40 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:25:41 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t k)
{
	int		len_a;
	size_t	len_b;
	int		lenb_buff;

	len_b = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[len_b] != '\0' && len_b < k)
	{
		len_a = 0;
		lenb_buff = len_b;
		while (s1[len_b] == s2[len_a] && len_b < k)
		{
			len_a++;
			len_b++;
			if (s2[len_a] == '\0')
				return ((char *)&s1[lenb_buff]);
		}
		len_b = lenb_buff;
		len_b++;
	}
	return (NULL);
}
