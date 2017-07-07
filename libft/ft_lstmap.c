/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:19:47 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/30 17:19:48 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	p = f(lst);
	tmp = p;
	while ((lst = lst->next))
	{
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (p);
}
