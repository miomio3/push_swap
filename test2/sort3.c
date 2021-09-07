#include "push_swap.h"

int	is_sortedAB(t_list *p, int a_b)
{
	t_list	*first;
	t_list	*last;
	t_list	*ptr;
	int		i;

	first = search_smallest(p, a_b);
	ptr = first;
	i = 0;
	while(ptr->num <= search_next(ptr, a_b)->num && (ptr != first || i == 0))
	{
		ptr = search_next(ptr, a_b);
		i++;
	}
	if((ptr->next ==  || search_prev(ptr, a_b)->num == ptr->num) && i > 0)
		return(SORTED);
	ptr = first;
	i = 0;
	while(ptr->num <= search_prev(ptr, a_b)->num && (ptr != first || i == 0))
	{
		ptr = search_prev(ptr, a_b);
		i++;
	}
	if((ptr == search_next(first, a_b) || ptr->num == search_prev(ptr, a_b)->num) && i > 0)
		return(SORTED);
	return(NOSORTED);
}

int	is_around_sortedB(t_list *p)
{
	t_list	*next;
	t_list	*prev;

	next = p->next;
	prev = search_prev(p, B);
	if(next->sorted == SORTED && p->num >= next->num)
	{
		if(prev->sorted == SORTED && p->num > prev->num && is_sortedAB(p, B) == NOSORTED)
			return(NOSORTED);
		return(SORTED);
	}
	else if(prev->sorted == SORTED && p->num <= prev->num)
	{
		if(next->sorted == SORTED && p->num > next->num && is_sortedAB(p, B) == NOSORTED)
			return(NOSORTED);
		return(SORTED);
	}
	return(NOSORTED);
}

int	is_around_sortedA(t_list *p)
{
	t_list	*next;
	t_list	*prev;

	prev = p->prev;
	next = search_next(p, A);
	if(prev->sorted == SORTED && p->num <= prev->num)
	{
		if(next->sorted == SORTED && p->num < next->num && is_sortedAB(p, A) == NOSORTED)
			return(NOSORTED);
		return(SORTED);
	}
	else if(next->sorted == SORTED && p->num >= next->num)
	{
		if(prev->sorted == SORTED && p->num > prev->num && is_sortedAB(p, A) == NOSORTED)
			return(NOSORTED);
		return(SORTED);
	}
	return(NOSORTED);
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
	while(is_around_sortedA(pa) == NOSORTED && is_around_sortedB(pb) == NOSORTED)
		ss_rr(pa);
	while(is_around_sortedA(pa) == NOSORTED)
		sa_ra(pa);
	while(is_around_sortedB(pb) == NOSORTED)
		sb_rb(pa);
	search_Alast(pa)->sorted = SORTED;
	search_Blast(pa)->sorted = SORTED;
}