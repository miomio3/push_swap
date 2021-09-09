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
	t_list	*lastsorted;
	int		rb2top;
	int		rrb2top;
	int		i;

	lastsorted = search_last_biggestarray_sorted(p, B);
	if(lastsorted->sorted == NOSORTED)
		return;
	rb2top = rb2top_times(lastsorted) - 1;
	rrb2top = rrb2top_times(lastsorted);
	i = 0;
	if(rb2top < rrb2top)
		while(i++ < rb2top)
			sb_rb(p);
	else
		while(i++ < rrb2top)
			rrb_sb(p);

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