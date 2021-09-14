#include "push_swap.h"

int	isA_over3(t_list *list)
{
	t_list	*last;

	last = searchA_last(list);
	if(last->order < 3)
		return(UNDER);
	else
		return(OVER);
}

int	isB_over3(t_list *list)
{
	t_list	*first;
	t_list	*last;

	last = search_last(list);
	first = searchB_first(list);
	if(last->order - first->order < 3)
		return(UNDER);
	else
		return(OVER);
}

int	isA_sorted_enst(t_list *list)
{
	t_list	*p;
	t_list	*next;

	p = searchA_start(list);
	while(p->enst != END)
	{
		next = search_next(p, A);
		if(p->arrayorder > next->arrayorder)
			return(NOSORTED);
	}
	return(SORTED);
}
