#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"

#define BUFFER_SIZE 30

static int		ft_srchln(int j, char **str, char **line, int use)
{
	char	*new;

	new = *str;
	if (use == 0)
		while (new[j] != '\n' && new[j] != '\0')
			j++;
	else
	{
		*line = ft_strnew(j);
		*line = ft_strncpy(*line, new, j);
		if (new[j] == '\n')
		{
			j++;
			if (ft_strlen(new) - j != 0)
				new = ft_strdup(new + j);
			else
				ft_strdel(str);
			new = (new) ? new : NULL;
		}
	}
	*str = new;
	return (j);
}

/*
**i[0] = buf, i[1] = string to cpy, i[2] = while flag
*/


int		get_next_line(const int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	static char	*str;
	int		i[3];

	i[0] = 1;
	i[2] = 1;
	i[1] = (!str) ? 0 : ft_srchln(i[1], &str, line, 0);
	str = (i[1] == 0) ? ft_strnew(0) : str;
	i[2] = (i[1] == 0) ? 1 : 0;
	while (i[0] && i[2] == 1)
	{
		i[0] = read(fd, buf, BUFFER_SIZE);
		if (i[0] == -1)
			return (-1);
		buf[i[0]] = '\0';
		str = ft_sfstrjoin(str, buf, 1);
		i[1] = ft_srchln(i[1], &str, line, 0);
//		ft_putendl(str);
//		ft_putnbrendl(i[1]);
		i[2] = (str[i[1]] == '\n') ? 0 : 1;
//		ft_putnbrendl(i[2]);
	}
	ft_srchln(i[1], &str, line, 1);
//	ft_putendl(str);
	return ((i[0] == 0) ? 0 : 1);
}
