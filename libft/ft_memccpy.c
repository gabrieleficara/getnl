/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:29:11 by gficara           #+#    #+#             */
/*   Updated: 2017/11/18 16:03:24 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char		*s;
	unsigned char			*d;
	unsigned int			i;
	unsigned char			m;

	s = src;
	d = dst;
	m = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s[i] == m)
		{
			d[i] = s[i];
			i++;
			return (&d[i]);
		}
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
