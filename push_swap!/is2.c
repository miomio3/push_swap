#include "push_swap.h"

int	countA2end(t_list *list)
{
	t_list	*start;
	t_list	*last;

	start = searchA_start(list);
	last = searchA_last(list);
	return(last->order - start->order + 1);
}

int	isA_sorted(t_list *list)
{
	t_list	*p;
	t_list	*first;
	int		i;

	p = searchA_last(list);
	first = p;
	i = 0;
	while(p != first || i == 0)
	{
		if(p->num > search_prev(p, A)->num)
			return(NOSORTED);
		p = search_prev(p, A);
	}
	return(SORTED);
}

int	isA_over2(t_list *list)
{
	t_list	*p;
	int		i;

	i = countA2end(list);
	if(i > 2)
		return(OVER);
	else
		return(UNDER);
}