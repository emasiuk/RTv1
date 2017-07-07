/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:33:14 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/24 14:15:10 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int len_a;
	int len_b;
	int lenb_buff;

	len_b = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[len_b] != '\0')
	{
		len_a = 0;
		lenb_buff = len_b;
		while (s1[len_b] == s2[len_a])
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
