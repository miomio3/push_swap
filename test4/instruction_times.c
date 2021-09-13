#include "push_swap.h"

int	ra2top_times(t_list *pa)
{
	return(search_Alast(pa)->order - pa->order);
}

int	rra2top_times(t_list *pa)
{
	return(pa->order + 1);
}

int	rb2top_times(t_list *pb)
{
	return(pb->order - search_Bfirst(pb)->order);
}

int	rrb2top_times(t_list *pb)
{
	return(search_last(pb)->order - pb->order + 1);
}