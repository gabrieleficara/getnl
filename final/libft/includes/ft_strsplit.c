/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:54:04 by gficara           #+#    #+#             */
/*   Updated: 2017/11/18 18:58:05 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntwrd(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static char	**all(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_cntwrd(s, c)) + 1);
	if (!tab)
		return (NULL);
	return (tab);
}

/*
** i[0] go trough all, i[1] end of word, i[2] begin of word,i[3] current string
*/

char		**ft_strsplit(char const *s, char c)
{
	int		i[4];
	char	**tab;

	tab = all(s, c);
	if (!tab)
		return (NULL);
	i[0] = 0;
	i[3] = 0;
	while (s[i[0]])
	{
		i[1] = 0;
		while (s[i[0]] && s[i[0]] == c)
			i[0]++;
		if (s[i[0]])
		{
			i[2] = i[0];
			while (s[i[0]] && s[i[0]++] != c)
				i[1]++;
			tab[i[3]] = ft_strsub(s, i[2], i[1]);
			if (!tab[i[3]++])
				return (NULL);
		}
	}
	tab[i[3]] = NULL;
	return (tab);
}
