/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:16:09 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/28 18:16:10 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned long	dst_len;
	unsigned long	src_len;
	int				i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	if (n == 0)
		return (src_len);
	dest += dst_len;
	i = n - MIN(dst_len, n);
	while (--i > 0 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (src_len + MIN(dst_len, n));
}
