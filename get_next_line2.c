#include "libft/libft.h"

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFF_SIZE 32

static int		cntsv(char *buf, t_list **copy, int read)
{
	int		i;
	t_list	*cpy;
	char	*str;

	i = 0;
	while (buf[i] != '\n' && i < read)
		i++;
	str = (char *)malloc(i * sizeof(char));
	str = ft_memmove(str, buf, i);
	cpy = ft_lstnew(str, i);
	ft_lstadd(copy, cpy);
	return ((buf[i] == '\n') ? i + 1 : i);
}

static t_list	*srchfd(t_list **head, int fd, t_list **cpy)
{
	t_list	*ptr;

	if (!head)
	{
		head = (t_list **)malloc(sizeof(t_list *));
		*head = NULL;
	}
	ptr = *head;
	while (ptr != NULL || ptr->content_size == fd)
		ptr = ptr->next;
	if (ptr == NULL)
	{
		ptr = ft_lstnew(NULL, 0);
		ptr->content_size = fd;
		ft_lstadd(head, ptr);
	}
	return (ptr);
}

static int		allcpy(char **line, int j, t_list **cpy, int ret)
{
	int		i;
	int		k;
	char	*str;
	char	*cont;
	t_list	*ptr;

	str = *line;
	ptr = *cpy;
	*line = ft_strnew(j);
	i = 0;
	while (ptr)
	{
		k = 0;
		cont = (char *)ptr->content;
		while (k < ptr->content_size)
			str[i++] = (char)(cont)[k++];
		i = i + ptr->content_size;
		ptr = ptr->next;
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	**head;
	t_list			**cpy;
	char			buf[BUFF_SIZE];
	t_list			*str;
	int				rd[2];
	int				j;

	rd[1] = 1;
	cpy = (t_list **)malloc(sizeof(t_list *));
	*cpy = NULL;
	srchfd(head, fd, cpy);
	rd[0] = read(fd, &buf, BUFF_SIZE);
	while (rd[0])
	{
		rd[1] = rd[1] + cntsv(buf, head, rd[0]);
		if ((*head)->content_size != rd[1])
			return ();
		rd[0] = read(fd, &buf, BUFF_SIZE);
	}
}
