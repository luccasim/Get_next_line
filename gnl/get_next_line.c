#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
# define PUT(a)	ft_putendl(a);

char	*save_line(char *cpy, char **line)
{
	char	*tmp;
	char	*save;

	if ((tmp = ft_strchr(cpy, '\n')))
	{
		*tmp = 0;
		*line = ft_strdup(cpy);
		save = ft_strdup(++tmp);
		free(cpy);
		return (save);
	}
	return (save);
}

int		read_line(int fd, char **line, char **save)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char	*cpy;

	cpy =  *save;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		tmp = cpy;
		cpy = ft_strjoin(tmp, buf);
		free(tmp);
		if ((*save = save_line(cpy, line)))
			return (1);
	}
	if (cpy && ret > -1)
	{
		if (!*cpy)
			return (0);
		if (!(*save = save_line(cpy, line)))
		{
			*line = ft_strdup(cpy);
			free(cpy);
		}
		return (1);
	}
	return (ret);
}

// void	aff_save(char *save)
// {
// 	ft_putstr("[");
// 	ft_putstr(save);
// 	ft_putendl("]");
// }

int		get_next_line(int fd, char **line)
{
	int			ret;
	static		char *save = 0;

	if (fd < 0 || !line)
		return (-1);
	*line = 0;
	ret = read_line(fd, line, &save);
	if (ret == 0)
	{
		PUT("end of file");
		free(save);
	}
	return (ret);
}