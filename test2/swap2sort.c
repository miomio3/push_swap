#include "push_swap.h"

int	is_sortedAB(t_list *p, int a_b)
{
	t_list	*first;
	t_list	*ptr;
	int		i;

	first = search_smallestlast(p, a_b);
	ptr = first;
	while(ptr->num <= search_prev(ptr, a_b)->num && search_prev(ptr, a_b) != first)
		ptr = search_prev(ptr, a_b);
	if(search_prev(ptr, a_b) == first)
		return(SORTED);
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
	
	search_Alast(pa)->sorted = SORTED;
	search_Blast(pa)->sorted = SORTED;
}