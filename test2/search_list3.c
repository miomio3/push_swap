#include "push_swap.h"

t_list	*search_smallest_sorted(t_list *p, int a_b)
{
	t_list	*ptr;

	ptr = search_firstsorted(p, a_b);
	while(ptr->num >= search_next(p, a_b)->num && ptr != search_next(p, a_b))
		ptr = search_next(ptr, a_b);
	return(ptr);
}