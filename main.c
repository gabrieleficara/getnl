/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:44:21 by gficara           #+#    #+#             */
/*   Updated: 2017/12/20 14:20:16 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, const char *argv[])
{
	int		fd;
	char	*new;
	int		i;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	i = 1;
	while (i == 1)
	{
		i = get_next_line(fd, &new);
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putendl(new);
	}
	fd = close(fd);
	return (0);
}
