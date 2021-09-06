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
	while(pa->prev->sorted != SORTED && pb->next->sorted != SORTED)
		ss_rr(pa);
	while(pa->prev->sorted != SORTED)
		sa_ra(pa);
	while(pb->next->sorted != SORTED)
		sb_rb(pa);
	search_Alast(pa)->sorted = SORTED;
	search_Blast(pa)->sorted = SORTED;
}