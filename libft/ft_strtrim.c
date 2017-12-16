/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:41:58 by gficara           #+#    #+#             */
/*   Updated: 2017/11/21 20:10:36 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findj(char const *s, int i)
{
	int		j;

	while (s[i])
	{
		while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
			i++;
		j = i;
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
	}
	return (j);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s)
		return (NULL);
	if (!*s)
	{
		str = ft_strnew(0);
		return (str);
	}
	i = 0;
	j = 0;
	k = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	k = i;
	j = ft_findj(s, i);
	str = ft_strnew(j - k);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, &s[k], j - k);
	str[j - k] = '\0';
	return (str);
}
