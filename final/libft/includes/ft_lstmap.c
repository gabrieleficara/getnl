/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:04:12 by gficara           #+#    #+#             */
/*   Updated: 2017/11/17 16:08:06 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;

	if (lst != NULL)
	{
		ptr = ft_lstmap(lst->next, f);
		lst = f(lst);
		if (!lst)
			return (NULL);
		lst->next = ptr;
		return (lst);
	}
	return (NULL);
}
