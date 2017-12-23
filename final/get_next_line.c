/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:49:15 by gficara           #+#    #+#             */
/*   Updated: 2017/12/23 11:45:55 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_srchln(int j, char **str, char **line, int use)
{
	char	*new;
	char	*ptr;

	new = *str;
	if (use == 0)
		while (new[j] != '\n' && new[j] != '\0')
			j++;
	else
	{
		*line = ft_strnew(j);
		*line = ft_strncpy(*line, new, j);
		if (new[j] == '\n' || new[j] == '\0')
		{
			j = (new[j] == '\n') ? j + 1 : j;
			if (new[j])
				ptr = ft_strdup(new + j);
			else
				ptr = NULL;
			ft_strdel(&new);
			*str = ptr;
		}
	}
	return ((use == 0) ? j : 1);
}

static void	init(int *i, char **str, char **line)
{
	i[0] = 1;
	i[1] = 0;
	i[2] = 1;
	i[3] = 0;
	if (*str)
	{
		i[1] = ft_srchln(i[1], str, line, 0);
		i[2] = ((*str)[i[1]] == '\n') ? 0 : 1;
		i[3]++;
	}
	else
		*str = ft_strnew(0);
}

static int	end(int *i, char **str, char **line)
{
	if (**str == '\0')
	{
		ft_strdel(str);
		if (i[0] == -1)
			return (-1);
		return (0);
	}
	return (ft_srchln(i[1], str, line, 1));
}

/*
**i[0] = buf, i[1] = string to cpy, i[2] = while flag
*/

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*str = NULL;
	int			i[4];

	init(i, &str, line);
	while (i[0] && i[2] == 1)
	{
		i[0] = read(fd, buf, BUFF_SIZE);
		if (i[0] == -1 || (i[0] == 0 && i[3]++ == 0))
			break ;
		buf[i[0]] = '\0';
		if (!(str = ft_sfstrjoin(str, buf, 1)))
			return (-1);
		i[1] = ft_srchln(i[1], &str, line, 0);
		i[2] = (str[i[1]] == '\n') ? 0 : 1;
	}
	return (end(i, &str, line));
}
