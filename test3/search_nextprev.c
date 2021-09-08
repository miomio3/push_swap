#include "push_swap.h"

t_list	*search_prev(t_list *p, int a_b)
{
	t_list	*prev;

	if(p->prev->a_b != a_b)
	{
		if(a_b == A)
			prev = search_Alast(p);
		else
			prev = search_last(p);
	}
	else
		prev = p->prev;
	return(prev);
}

t_list	*search_next(t_list *p, int a_b)
{
	t_list	*next;

	if(p->next->a_b != a_b)
	{
		if(a_b == A)
			next = search_list(p, 0);
		else
			next = search_Blast(p);
	}
	else
		next = p->next;
	return(next);
}

