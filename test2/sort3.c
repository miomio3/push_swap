#include "push_swap.h"

int	is_around_sorted(t_list *p, int a_b)
{
	t_list	*next;
	t_list	*prev;

	next = search_next(p, a_b);
	prev = search_prev(p, a_b);
	if(next->sorted == SORTED && p->num >= next->num)
	{
		if(prev->sorted == SORTED && p->num > prev->num)
			return(NOSORTED);
		else
			return(SORTED);
	}
	return(SORTED);
}

void	swap2sort(t_list *pa, t_list *pb, int i)
{
	t_list	*sortedA;
	t_list	*sortedB;

	if(i == 0)
	{
		pa->sorted = SORTED;
		pb->sorted = SORTED;
		return;
	}
	while(is_around_sorted(pa, A) == NOSORTED && is_around_sorted(pb, B) == NOSORTED)
		ss_rr(pa);
	while(is_around_sorted(pa, A) == NOSORTED)
		sa_ra(pa);
	while(is_around_sorted(pb, B) == NOSORTED)
		sb_rb(pa);
	search_Alast(pa)->sorted = SORTED;
	search_Blast(pa)->sorted = SORTED;
}