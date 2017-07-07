/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:45:57 by emasiuk           #+#    #+#             */
/*   Updated: 2016/11/30 13:45:58 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *cont, size_t cont_size)
{
	t_list *lst;

	if ((lst = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (0);
	if (cont == NULL)
	{
		lst->content_size = 0;
		lst->content = NULL;
	}
	else
	{
		if ((lst->content = (void*)malloc(sizeof(cont_size))) == NULL)
			return (0);
		ft_memcpy(lst->content, cont, cont_size);
		lst->content_size = cont_size;
	}
	lst->next = NULL;
	return (lst);
}
