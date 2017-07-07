/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:14:25 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/29 14:14:27 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int		dop_len(int n, int sign)
{
	int len;

	len = 0;
	while (n /= 10)
		len++;
	len += sign;
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*s;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	len = dop_len(n, sign) + 2;
	if ((s = (char*)malloc(sizeof(char) * (len))) == NULL)
		return (0);
	s[--len] = '\0';
	while (len--)
	{
		s[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		s[0] = '-';
	return (s);
}
