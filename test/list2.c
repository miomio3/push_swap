#include "push_swap.h"

int	search_Alast(t_list	*list)
{
	t_list	*p;
	int		i;

	p = search_list(list, 0);
	i = 0;
	while(p->a_b == A && (p->prev->last == 0 || i++ == 0))
		p = p->next;
	p = p->prev;
	return(p->order);
}

int	search_Blast(t_list	*list)
{
	t_list	*p;

	p = search_list(list, 0);
	while(p->a_b == A && p->last != 1)
		p = p->next;
	return(p->order);
}

void	free_list(t_list *list)
{
	t_list	*p;

	p = list;
	while(p)
	{
		free(p);
		list = NULL;
	}
}