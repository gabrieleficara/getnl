#include <fcntl.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFFER_SIZE		10

int get_next_line(const int fd, char **line);

int main(int argc, const char *argv[])
{
	int		fd;
	int		i;
	char	buf[BUFFER_SIZE + 1];
	char	*new;

	if (argc != 2)
		return (0);
	fd = open(argv [1], O_RDONLY);
	i = get_next_line(fd, &new);
	ft_putendl(new);
	i = get_next_line(fd, &new);
	ft_putendl(new);
	fd = close(fd);
	return 0;
}
/*
	i = read(fd, buf, BUFFER_SIZE);
	buf[i] = '\0';
	new = ft_strdup(buf);
	while (i)
	{
	i = read(fd, buf, BUFFER_SIZE);
	buf[i] = '\0';
	new = ft_sfstrjoin(new, buf, 1);
	ft_putnbrendl(i);
	}
*/
