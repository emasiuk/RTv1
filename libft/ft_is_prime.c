/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:41:35 by emasiuk           #+#    #+#             */
/*   Updated: 2016/12/07 12:41:36 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_is_prime(int n)
{
	int i;
	int counter;

	counter = 0;
	i = 2;
	while (i <= (n / 2))
	{
		if (n % i == 0)
			counter++;
		i++;
	}
	if (counter != 0)
		return (0);
	else
		return (1);
}
