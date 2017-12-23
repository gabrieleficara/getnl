/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:59:25 by gficara           #+#    #+#             */
/*   Updated: 2017/11/17 19:45:26 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_lenn(long int num)
{
	int		i;

	i = 0;
	if (num <= 0)
	{
		i++;
		num = ft_abs(num);
	}
	while (num > 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	num;

	i = ft_lenn(n);
	str = (char*)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	num = ft_abs(n);
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		i--;
		str[i] = (num % 10) + 48;
		num = num / 10;
	}
	if (n < 0)
	{
		i--;
		str[i] = '-';
	}
	return (str);
}
