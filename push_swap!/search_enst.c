#include "push_swap.h"

t_list	*searchA_start(t_list *list)
{
	t_list	*p;

	p = searchA_last(list);
	while(p->enst != START)
		p = p->prev;
	return(p);
}

t_list	*searchB_start(t_list *list)
{
	t_list	*p;

	p = searchB_first(list);
	while(p->enst != START)
		p = p->next;
	return(p);
}

t_list	*searchA_end(t_list *list)
{
	t_list	*p;

	p = searchA_start(list);
	while(p->enst != END)
		p = search_next(p, A);
	return(p);
}

t_list	*searchB_end(t_list *list)
{
	t_list	*p;

	p = searchB_start(list);
	while(p->enst != END)
		p = search_prev(p, B);
	return(p);
}