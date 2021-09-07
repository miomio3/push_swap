#include "push_swap.h"

t_list	*search_smallest(t_list *p, int a_b)
{
	t_list	*ptr;
	t_list	*first;
	t_list	*re;
	int		i;

	if(a_b == A)
		first = search_Alast(p);
	else
		first = search_Blast(p);
	ptr = first;
	re = first;
	i = 0;
	while(ptr != first || i++ == 0)
	{
		if(ptr->num >= search_next(ptr, a_b)->num)
			re = search_next(ptr, a_b);
		ptr = search_next(ptr, a_b);
	}
	return(re);
}