/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfstrjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:43:40 by gficara           #+#    #+#             */
/*   Updated: 2017/12/20 15:19:24 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sfstrjoin(char const *s1, char const *s2, int c)
{
	char *ret;

	ret = ft_strjoin(s1, s2);
	if (c == 1 || c == 3)
		ft_strdel((char **)&s1);
	if (c == 2 || c == 3)
		ft_strdel((char **)&s2);
	return (ret);
}
