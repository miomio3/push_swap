#include "push_swap.h"

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
	sortedA = search_firstsorted(pa, A);
	sortedB = search_firstsorted(pb, B);
	while(pa->prev->sorted != SORTED && pb->next->sorted != SORTED)
	{
		ss(pa);
		rr(pa);
	}
	while(pa->prev->sorted != SORTED)
	{
		sa(pa, PUT);
		ra(pa, PUT);
	}
	while(pb->next->sorted != SORTED)
	{
		sb(pa, PUT);
		ra(pa, PUT);
	}
	search_Alast(pa)->sorted = SORTED;
	search_Blast(pa)->sorted = SORTED;
}