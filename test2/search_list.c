#include "push_swap.h"

t_list	*search_last(t_list *list)
{
	return(search_list(list, 0)->prev);
}

/* 
t_list	*search_firstsorted(t_list *list, int a_b)
{
	t_list	*p;
	t_list	*last;

	if(a_b == A)
	{
		last = search_list(list, 0);
		p = search_Alast(list);
		while(p != last && p->sorted != SORTED)
			p = p->prev;
	}
	else
	{
		p = search_Blast(list);
		last = search_last(list);
		while(p != last && p->sorted != SORTED)
			p = p->next;
	}
	return(p);
}
 */

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

t_list	*search_list(t_list *list, int order)
{
	t_list	*p;

	p = list;
	while(p->order != order)
		p = p->next;
	return(p);
}
