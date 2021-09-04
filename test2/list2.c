#include "push_swap.h"

t_list	*search_Alast(t_list	*list)
{
	t_list	*p;
	int		i;

	p = search_list(list, 0);
	i = 0;
	while(p->a_b == A && (p->prev->last == 0 || i++ == 0))
		p = p->next;
	p = p->prev;
	return(p);
}

t_list	*search_Blast(t_list	*list)
{
	t_list	*p;

	p = search_list(list, 0);
	while(p->a_b == A && p->last != 1)
		p = p->next;
	return(p);
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

int	is_B(t_list *list)
{
	t_list	*p;

	p = list;
	while(p->a_b == A && p->last == 0)
		p = p->next;
	if(p->a_b == B)
		return(1);
	else
		return(-1);
}
