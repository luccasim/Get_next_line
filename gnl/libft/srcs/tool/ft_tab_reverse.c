#include "ft_tool.h"

void	ft_tab_reverse(int32_t *tab, uint32_t size)
{
	int32_t	i;
	int32_t	tmp;
	int32_t	j;

	if (!tab)
		return ;
	i = 0;
	while (i < size / 2)
	{
		j= size - 1 - i;
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
	}
}