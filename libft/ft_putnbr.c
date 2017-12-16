/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:10:15 by gficara           #+#    #+#             */
/*   Updated: 2017/11/17 18:40:37 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_print(long int num)
{
	if (num > 0)
	{
		ft_print(num / 10);
		ft_putchar((num % 10) + '0');
	}
}

void				ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar('0');
	else if (n > 0)
		ft_print(n);
	else
	{
		ft_putchar('-');
		ft_print(ft_abs(n));
	}
}
