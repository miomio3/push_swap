#include "push_swap.h"

void	push2topA(t_list *p)
{
	int	last;

	last = search_Alast(p)->order;
	if(p->order > last / 2)
	{
		while(p->order != last)
		{
			ra(p, PUT);
			p = p->next;
		}
	}
	else
	{
		while(p->order != last)
		{
			rra(p, PUT);
			p = search_prev(p, A);
		}
	}
}

void	swap2sortA(t_list *p)
{
	t_list	*firstsorted;
	int	ra2top;
	int	rra2top;
	int	sorted_order;
	int	p_order;
	int	i;

	firstsorted = search_last_biggestarray_sorted(p, A);
	if(firstsorted->sorted == NOSORTED)
		return;
	ra2top = ra2top_times(firstsorted);
	rra2top = rra2top_times(firstsorted) - 1;
	i = 0;
	if(ra2top < rra2top)
		while(i++ < ra2top)
			sa_ra(p);
	else
		while(i++ < rra2top)
			rra_sa(p);
}

void	sortA(t_list *list, int *array, int argc, int nowi)
{
	int		i;
	t_list	*p;

	i = nowi;
	while(i < argc - 1 - PUSH2B && is_sortedAB(list, A) == NOSORTED)
	{
		p = search_smallestarray_nosorted(list, A);
		push2topA(p);
		swap2sortA(search_Alast(p));
		search_Alast(p)->sorted = SORTED;
		i++;
	}
}
