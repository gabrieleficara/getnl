/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:18:36 by gficara           #+#    #+#             */
/*   Updated: 2017/11/12 13:19:09 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int				*b;
	unsigned int	i;

	b = malloc(size);
	if (!b)
		return (NULL);
	i = 0;
	while (i < size)
	{
		b[i] = 0;
		i++;
	}
	return (b);
}
