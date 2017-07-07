/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:12:28 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/29 14:12:29 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			cnt++;
		s++;
	}
	return (cnt);
}

static char	*skip_del(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static char	*goto_end(char const *s, char c)
{
	while (*s && *s != c)
		s++;
	return ((char *)s);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**table;
	int		wordscnt;
	char	*endw;
	int		i;

	if (!s)
		return (NULL);
	wordscnt = count_words(s, c);
	if (!(table = (char **)malloc(sizeof(char *) * (wordscnt + 1))))
		return (NULL);
	if (!*s)
		return ((char *[2]){NULL});
	i = 0;
	while (i < wordscnt)
	{
		s = skip_del(s, c);
		endw = goto_end(s, c);
		if (!(table[i] = ft_strsub(s, 0, endw - s)))
			return (NULL);
		s = endw;
		i++;
	}
	*(table + wordscnt) = NULL;
	return (table);
}
