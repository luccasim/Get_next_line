#include "ft_unix.h"

char	*ft_strchr(const char *s, int c);

int	ft_is_option(char c)
{
	char	*opt;

	opt = ft_options_sglt();
	if (!opt)
		return (FAIL);
	else
	{
		if (ft_strchr(opt, c))
			return (c);
		else
			return (FAIL);
	}
}