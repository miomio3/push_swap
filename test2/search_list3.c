#include "push_swap.h"

t_list	*search_first(t_list *list, int a_b)
{
	if(a_b == A)
		return(search_list(list, A));
	else
		return(search_Blast(list));
}


t_list	*search_smallest(t_list *list, int a_b)
{
	t_list	*first;
	t_list	*last;
	t_list	*re;
	t_list	*p;

	if(a_b == A)
	{
		first = search_list(list, 0);
		last = search_Alast(list);
	}
	else
	{
		last = search_Blast(list);
		first = search_last(list);
	}
	re = first;
	p = first;
	while(p != last)
	{
		if(p->num <= re->num)
			re = p;
		p = p->next;
	}
	while(re->prev->num == re->num && re != first)
		re = re->prev;
	return(re);
}
