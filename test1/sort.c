#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_list	*p;

	p = search_list(list, 0);
	while(p->num >= p->next->num && p->last == 0)
		p = p->next;
	if(p->last == 1)
		return(1);
	else
		return(-1);
}
