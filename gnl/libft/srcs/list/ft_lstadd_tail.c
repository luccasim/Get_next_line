#include "list.h"

void	ft_lstadd_tail(t_list *lst, t_list *new)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}