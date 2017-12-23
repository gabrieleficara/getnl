/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:12:18 by gficara           #+#    #+#             */
/*   Updated: 2017/11/17 18:41:04 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_print(long int num, int fd)
{
	if (num > 0)
	{
		ft_print(num / 10, fd);
		ft_putchar_fd((num % 10) + '0', fd);
	}
}

void				ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n > 0)
		ft_print(n, fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_print(ft_abs(n), fd);
	}
}
