#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		pid;

	if (ac == 2)
	{
		line = 0;
		fd = open(*++av, O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			ft_putendl(line);
			ft_strdel(&line);
		}
		// pid = getpid();
		// ft_putnbr(pid);
		// sleep(20);
	}
	return (0);
}