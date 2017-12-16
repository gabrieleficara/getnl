/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:32:10 by gficara           #+#    #+#             */
/*   Updated: 2017/11/21 17:19:57 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init(int *i, long long int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 1;
}

int			ft_atoi(const char *str)
{
	int				i;
	int				k;
	int				j;
	long long int	num;

	ft_init(&i, &num, &k);
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\f' ||
			str[i] == '\n' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		k = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i++] - '0');
	}
	return (num * k);
}
