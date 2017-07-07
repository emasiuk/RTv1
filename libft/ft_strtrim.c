/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:10:42 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/29 13:10:42 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;

	if (s == '\0')
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s);
	while (*s && (*(s + len - 1) == ' ' || *(s + len - 1) == '\n'
		|| *(s + len - 1) == '\t'))
		len--;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, s, len);
	return (str);
}
