#include "push_swap.h"

t_list	*search_last(t_list *list)
{
	return(search_list(list, 0)->prev);
}


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

t_list	*search_Bfirst(t_list	*list)
{
	t_list	*p;

	p = search_list(list, 0);
	while(p->a_b == A && p->last != 1)
		p = p->next;
	return(p);
}

t_list	*search_list(t_list *list, int order)
{
	t_list	*p;

	p = list;
	while(p->order != order)
		p = p->next;
	return(p);
}
