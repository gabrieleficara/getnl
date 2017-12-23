/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:09:01 by gficara           #+#    #+#             */
/*   Updated: 2017/11/18 16:56:19 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s;
	unsigned char		*d;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (s < d)
	{
		s = s + (len - 1);
		d = d + (len - 1);
		while (len > 0)
		{
			*d-- = *s--;
			len--;
		}
	}
	else
		while (len > 0)
		{
			*d++ = *s++;
			len--;
		}
	return (dst);
}
