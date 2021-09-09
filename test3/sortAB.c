#include "push_swap.h"

void	sortAB(t_list *list)
{
	t_list	*pa;
	t_list	*pb;
	int		lastA;
	int		lastB;
	int		final;
	int		difference;
	int		i;

	pa = search_smallestlast(pa, A);
	pb = search_smallestlast(pb, B);
	lastA = search_Alast(list)->order;
	lastB = search_Blast(list)->order;
	final = search_last(list)->order;
	difference = final - lastB;
	i = 0;
	if(pa->order > lastA / 2)
		while(i++ < lastA - pa->order)
			ra(list, PUT);
	else
		while(i++ < pa->order + 1)
			rra(list, PUT);
	i = 0;
	if(pb->order - lastB < difference / 2)
		while(i++ < pb->order - lastB + 1)
			rb(list, PUT);
	else
		while(i++ < final - pb->order)
			rrb(list, PUT);
}