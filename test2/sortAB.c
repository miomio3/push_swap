#include "push_swap.h"

void	sortAB(t_list *list)
{
	t_list	*pa;
	t_list	*pb;
	int		lastA;
	int		lastB;
	int		i;

	pa = search_smallestlast(list, A);
	pb = search_smallestlast(list, B);
	lastA = search_Alast(list)->order;
	lastB = search_last(list)->order;
	i = -1;
	while(++i < lastA - pa->order)
		ra(list, PUT);
	i = -1;
	while(++i < lastB - pb->order)
		rrb(list, PUT);
}