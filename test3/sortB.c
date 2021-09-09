#include "push_swap.h"

void	push2topB(t_list *p)
{
	int	last;
	int	difference;

	last = search_Blast(p)->order;
	difference = search_last(p)->order - last;
	if(p->order - last < difference / 2)
	{
		while(p->order != last)
		{
			rrb(p, PUT);
			p = search_next(p, B);
		}
	}
	else
	{
		while(p->order != last)
		{
			rb(p, PUT);
			p = p->prev;
		}
	}
}

void	swap2sortB(t_list *p)
{
	t_list	*firstsorted;
	int		sorted_order;
	int		difference;
	int		last;
	int		final;
	int		i;

	firstsorted = search_smallestarray_sorted(p, B);
	if(firstsorted->sorted == NOSORTED)
		return;
	sorted_order = firstsorted->order;
	last = search_Blast(p)->order;
	final = search_last(p)->order;
	difference = final - last;
	i = 0;
	if(sorted_order - last > difference / 2)
		while(i++ < sorted_order - last - 1)
			sb_rb(p);
	else
		while(i++ < final - sorted_order)
			sb_rrb(p);

}

void	sortB(t_list *list, int *array, int argc, int nowi)
{
	int		i;
	t_list	*p;

	i = nowi;
	while(i < PUSH2B && is_sortedAB(list, B) == NOSORTED)
	{
		p = search_smallestarray_nosorted(list, B);
		push2topB(p);
		swap2sortB(search_Blast(p));
		search_Blast(p)->sorted = SORTED;
		i++;
	}
}