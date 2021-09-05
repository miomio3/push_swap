#include "push_swap.h"

t_list	*search_last(t_list *list)
{
	return(search_list(list, 0)->prev);
}

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
	if(p->sorted == NOSORTED)
		return(NULL);
	return(p);
}