/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:48:08 by gficara           #+#    #+#             */
/*   Updated: 2017/11/21 11:50:16 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_rec(char *s, void (*f)(unsigned int, char *), int i)
{
	if (s[i])
	{
		f(i, s + i);
		i++;
		ft_rec(s, f, i);
	}
}

void			ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	if (s != NULL && f != NULL)
		ft_rec(s, f, 0);
}
