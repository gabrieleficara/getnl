/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:48:47 by gficara           #+#    #+#             */
/*   Updated: 2017/11/18 19:25:04 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	j;
	unsigned char	*str;

	if (n == 0)
		return (NULL);
	i = 0;
	j = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n - 1 && str[i] != j)
		i++;
	if (str[i] == j)
		return ((void *)&str[i]);
	return (NULL);
}
